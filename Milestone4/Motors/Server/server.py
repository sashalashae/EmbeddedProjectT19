from BaseHTTPServer import HTTPServer, BaseHTTPRequestHandler
from SocketServer import ThreadingMixIn
import threading
import json
from json import loads
import sys
import time

if len(sys.argv) < 4:
    print "Provide values for coefficients for PID algorithm."
    print "Usage: ", sys.argv[0], " <KP> <KI> <KD>"
    sys.exit()

KP = sys.argv[1]
KI = sys.argv[2]
KD = sys.argv[3]

currentmove = "none"

left_errors = []
total_left_errors = []
right_errors = []
total_right_errors = []

class Handler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.end_headers()
        message = threading.currentThread().getName()
        data = str(self.rfile.read(int(self.headers.getheader('Content-Length'))))
        print("GET Received:", data)
        
        #global count
        global currentmove
        
        if "Coefficients" in data:
            msg_to_send = "{KPKIKD"+str(KP).zfill(5)+str(KI).zfill(5)+str(KD).zfill(5)+'\0'+'}'
            print("Sending:", msg_to_send)
            self.wfile.write(msg_to_send)
        elif "Acknowledge" in data:
            while currentmove == "none":
                time.sleep(1)
            msg_to_send = "{"+currentmove+"\0}"
            print("Sending:", msg_to_send)
            self.wfile.write(msg_to_send)
            if currentmove != "none":
                currentmove = "none"
        elif "errors" in data.lower():
            info = {"Left Error" : left_errors, "Accumulated Left Errors" : total_left_errors,
                    "Right Error" : right_errors, "Accumulated Right Errors" : total_right_errors}
            msg_to_send = json.dumps(info)
            print("Sending:", msg_to_send)
            self.wfile.write(msg_to_send)

        return
    
    def do_POST(self):
        self.send_response(200)
        self.end_headers()
        data = str(self.rfile.read(int(self.headers.getheader('Content-Length'))))
        jdata = json.loads(data)
        
        print("POST Received: ", jdata)
        
        global currentmove
        global left_errors
        global total_left_errors
        global right_errors
        global total_right_errors
        
        msg_type = jdata["Type"]
        
        if "Instruction" in msg_type:
            currentmove = jdata["Content"]
            self.wfile.write(currentmove + '\0')
        elif "Error" in msg_type:
            error_data = jdata["Content"]
            #print "\tKP: ", int(error_data["KP"]), "\tKI: ", int(error_data["KI"]), "\tKD: ", int(error_data["KD"]) 
            left_errors.append(int(error_data["left"]))
            total_left_errors.append(int(error_data["total_l"]))
            right_errors.append(int(error_data["right"]))
            total_right_errors.append(int(error_data["total_r"]))
        return

class ThreadedHTTPServer(ThreadingMixIn, HTTPServer):
    pass
    
if __name__ == "__main__":
    server = ThreadedHTTPServer(('0.0.0.0', 2000), Handler)
    print('Starting server, use <Ctrl-C> to stop')
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        sys.exit()