from BaseHTTPServer import HTTPServer, BaseHTTPRequestHandler
from SocketServer import ThreadingMixIn
import threading
import json
from json import loads

class Handler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.close_connection = 0
        self.send_response(200)
        self.end_headers()
        message = threading.currentThread().getName()
        data = str(self.rfile.read(int(self.headers.getheader('Content-Length'))))
        jsondata = json.loads(data)
	print("GET processed")
        return

    def do_POST(self):
        self.close_connection = 0
        self.send_response(200)
        self.end_headers()
        rawdata = str(self.rfile.read(int(self.headers.getheader('Content-Length'))))
	print(rawdata)
	print("POST processed")
        return


class ThreadedHTTPServer(ThreadingMixIn, HTTPServer):
    """Handle requests in a separate thread."""

if __name__ == '__main__':
    server = ThreadedHTTPServer(('0.0.0.0', 2000), Handler)
    
    print('Starting server, use <Ctrl-C> to stop')
    server.serve_forever()
