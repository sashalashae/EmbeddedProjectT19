from BaseHTTPServer import HTTPServer, BaseHTTPRequestHandler
from SocketServer import ThreadingMixIn
import urlparse
import threading
import cgi
import json

class Handler(BaseHTTPRequestHandler):
    
    def do_GET(self):
        self.send_response(200)
        self.end_headers()
        message =  threading.currentThread().getName()
        rpath = self.path
        
        if(rpath == '/retdata'):
            #json.dump
            self.wfile.write(rpath)
        elif(rpath == '/adddata'):
            self.wfile.write(rpath)

            
        # self.wfile.write(rpath)
        # self.wfile.write('\n')
        return

    def do_POST(self):
        rpath = self.path


        if(rpath == '/adddata'):
            data = self.rfile.read(int(self.headers.getheader('Content-Length')))
            print(data)

        return
    

class ThreadedHTTPServer(ThreadingMixIn, HTTPServer):
    """Handle requests in a separate thread."""

if __name__ == '__main__':
    server = ThreadedHTTPServer(('localhost', 8080), Handler)
    print 'Starting server, use <Ctrl-C> to stop'
    server.serve_forever()
