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
import sys, os

client = MongoClient()
db = client.t19db
try:
    db.command("serverStatus")
except Exception as e:
    print(e)
else:
    print("Status: Connected")
collect = db.col

pr = 0
pc = 0
pm = 0
screq = 0
sm = 0
scres = 0
sir = 0


class Handler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.end_headers()
        message = threading.currentThread().getName()
        #rpath = self.path
        #jdump = json.dump(self.headers, self.fp)
        data = self.rfile.read(int(self.headers.getheader('Content-Length')))
        #self.send_header('Content-Length', data)
        stats = {
            "PIC Requests": pr,
            "PIC Correct": pc,
            "PIC Missed": pm,
            "Server Correct Req": screq,
            "Server Missed": sm,
            "Server Correct Res": scres,
            "Server Inc Reply": sir
        }
        self.send_header('Statistics', stats)
        '''
        if (rpath == '/retdata'):
            #json.dump
            self.wfile.write(rpath)
        elif (rpath == '/adddata'):
            self.wfile.write(rpath)
        '''
        # self.wfile.write(rpath)
        # self.wfile.write('\n')
        return

    def do_POST(self):
        if (collect.count() != 0):
            res = collect.find_one(sort=[('_id', -1)])
            print(res)
            '''
            #print(res)
            l = str(res).split(':')
            print(l)
            tempv = []
            tempv.append(l[1])
            tempv.append(l[3])
            tempv.append(l[5])
            tempv.append(l[7])
            tempv.append(l[8])
            print(tempv)
            '''
            '''
            for i in range(len(l)):
                if (i % 2 == 0):
                    for j in range(len(l[i])):
                        h = l[i]
                        if (h[j] != '"' or h[j] != "'" or h[j] != " "):
                            val.append(h[j:])
            res = [s.encode('utf-8') for s in res]
            print(val)
            '''
        else:
            instats = {
                "_id": 1,
                "PIC Requests": pr,
                "PIC Correct": pc,
                "PIC Missed": pm,
                "Server Correct Req": screq,
                "Server Missed": sm,
                "Server Correct Res": scres,
                "Server Inc Reply": sir
            }
            #data = self.rfile.read(
            #int(self.headers.getheader('Content-Length')))
            #file_data = ast.literal_eval(instats)
            collect.insert(instats)

        #Gets the data from the http as a JSON String

        #tdata = str(data)
        #print(sys.getsizeof(data))
        #file_data = ast.literal_eval(data)
        #print(file_data)
        #collect.insert(file_data)
        #print(collect.find_one())

        return


class ThreadedHTTPServer(ThreadingMixIn, HTTPServer):
    """Handle requests in a separate thread."""


if __name__ == '__main__':
    server = ThreadedHTTPServer(('localhost', 8080), Handler)
    pr = pr + 1
    print('Starting server, use <Ctrl-C> to stop')
    server.serve_forever()
