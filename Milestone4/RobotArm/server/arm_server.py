from BaseHTTPServer import HTTPServer, BaseHTTPRequestHandler
from SocketServer import ThreadingMixIn
import threading
import json
from json import loads

currentMove = "none"
commandNum = 0

class Handler(BaseHTTPRequestHandler):
    def do_GET(self):
	global currentMove
	global commandNum
        self.send_response(200)
        self.end_headers()
        message = threading.currentThread().getName()
        data = str(self.rfile.read(int(self.headers.getheader('Content-Length'))))
	print("GET received")
	#if request is PIC asking for move
        return

    def do_POST(self):
	global currentMove
	global commandNum
        self.send_response(200)
        self.end_headers()
        data = str(self.rfile.read(int(self.headers.getheader('Content-Length'))))
	print("POST received")
	#draw X command
	if data == "drawX":
		print("Draw O command received")
		commandNum = commandNum + 1
		self.wfile.write(str(commandNum))
	#draw O command
	elif data == "drawO":
		print("Draw X command received")
		commandNum = commandNum + 1
		self.wfile.write(str(commandNum))
	#check status
	elif data == "checkConnection":
		print("Connection check command received")
		commandNum = commandNum + 1
		self.wfile.write("Good Connection - Command " + str(commandNum))
	#reset command number
	elif data == "resetNumber":
		print("Command Number Reset Received")
		commandNum = 0
		self.wfile.write(str(commandNum))
	else:
		print("Error: Invalid POST body")
        return


class ThreadedHTTPServer(ThreadingMixIn, HTTPServer):
    """Handle requests in a separate thread."""

if __name__ == '__main__':
    server = ThreadedHTTPServer(('0.0.0.0', 2000), Handler)
    print('Starting server, use <Ctrl-C> to stop')
    server.serve_forever()
