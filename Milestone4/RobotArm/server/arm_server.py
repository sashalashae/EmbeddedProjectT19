from BaseHTTPServer import HTTPServer, BaseHTTPRequestHandler
from SocketServer import ThreadingMixIn
import urlparse
import threading
import cgi
import json
from json import loads
from pymongo import MongoClient
from pprint import pprint
import ast
import sys
import os
from ast import literal_eval

client = MongoClient()
db1 = client.t19p1

try:
    db1.command("serverStatus")
except Exception as e:
    print(e)
else:
    print("Status: Connected")

def utf8len(s):
    return len(s.encode('utf-8'))

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
