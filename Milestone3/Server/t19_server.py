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

# db2 = client.t19p2
# db3 = client.t19p3
# db4 = client.t19p4
try:
    db1.command("serverStatus")
    # db2.command("serverStatus")
    # db3.command("serverStatus")
    # db4.command("serverStatus")

except Exception as e:
    print(e)
else:
    print("Status: Connected")
collect = db1.pic1
collect2 = db1.pic2
collect3 = db1.pic3
collect4 = db1.pic4
gencollect = db1.gendata

pr = 0
pc = 0
pm = 0
screq = 0
sm = 0
scres = 0
sir = 0


def utf8len(s):
    return len(s.encode('utf-8'))


class Handler(BaseHTTPRequestHandler):
    def do_GET(self):
        # self.close_connection = 0
        self.send_response(200)
        self.end_headers()
        message = threading.currentThread().getName()
        data = str(
            self.rfile.read(int(self.headers.getheader('Content-Length'))))
        datal = json.loads(data)
        whichpi = datal.pop("Source")
        if (data1.pop("MsgType") == 'Stat'):
            if (whichpi == '1'):
                res = collect.find_one(sort=[('_id', -1)])
            elif (whichpi == '2'):
                res = collect2.find_one(sort=[('_id', -1)])
            elif (whichpi == '3'):
                res = collect4.find_one(sort=[('_id', -1)])
            elif (whichpi == '4'):
                res = collec4.find_one(sort=[('_id', -1)])
            stats = {
                "PIC Requests": res.pop("PIC Requests"),
                "PIC Correct": res.pop("PIC Correct"),
                "PIC Missed": es.pop("PIC Missed"),
                "Server Correct Req": res.pop("Server Correct Req"),
                "Server Missed": res.pop("Server Missed"),
                "Server Correct Res": res.pop("Server Correct Res"),
                "Server Inc Reply": res.pop("Server Inc Reply")
            }
            self.wfile.write(stats)
        else:
            self.wfile.write(data)
        return

    def do_POST(self):
        # self.close_connection = 0
        data = str(
            self.rfile.read(int(self.headers.getheader('Content-Length'))))
        datal = json.loads(data)
        leng = len(datal)
        whichpi = datal.pop("Source")
        k = False
        if (collect.count() != 0 or collect2.count() != 0
                or collect3.count() != 0 or collect4.count() != 0):
            if (whichpi == '1'):
                res = collect.find_one(sort=[('_id', -1)])
                k = True
            elif (whichpi == '2'):
                res = collect2.find_one(sort=[('_id', -1)])
                k = True
            elif (whichpi == '3'):
                res = collect4.find_one(sort=[('_id', -1)])
                k = True
            elif (whichpi == '4'):
                res = collec4.find_one(sort=[('_id', -1)])
                k = True
            if k == True:
                res.pop('_id')
                opr = res.pop("PIC Requests")
                opc = res.pop("PIC Correct")
                opm = res.pop("PIC Missed")
                oscreq = res.pop("Server Correct Req")
                osm = res.pop("Server Missed")
                oscres = res.pop("Server Correct Res")
                osir = res.pop("Server Inc Reply")
                diff = int(datal.pop("RID")) - int(opr)
                err = "None"
                if ((utf8len(data) != datal.pop("Checksum")) or (diff > 1)
                        or (leng != 9) or (data.find("MsgType") == False)
                        or (data.find("Symbol") == False)
                        or (data.find("NextLoc") == False)
                        or (data.find("Move") == False)
                        or (data.find("Encoder") == False)
                        or (data.find("Checksum"))):
                    if (diff > 1):
                        opm = diff + opm
                        osm = osm + diff
                        err = "Missed Request"
                    else:
                        opm = 1 + opm
                        osm = osm + 1
                        err = "added or lost value"
                else:
                    opc = opc + 1
                    oscreq = oscreq + 1
                    oscres = oscres + 1
                opr = opr + 1
                nstats = {
                    "PIC Requests": opr,
                    "PIC Correct": opc,
                    "PIC Missed": opm,
                    "Server Correct Req": oscreq,
                    "Server Missed": osm,
                    "Server Correct Res": oscres,
                    "Server Inc Reply": osir
                    "Error Type": 
                }
                if (whichpi == '1'):
                    collect.insert(nstats)
                elif (whichpi == '2'):
                    collect2.insert(nstats)
                elif (whichpi == '3'):
                    collect3.insert(nstats)
                elif (whichpi == '4'):
                    collect4.insert(nstats)
                self.wfile.write(nstats)
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
            collect.insert(instats)
            collect2.insert(instats)
            collect3.insert(instats)
            collect4.insert(instats)
            gencollect.insert(data)

        return


class ThreadedHTTPServer(ThreadingMixIn, HTTPServer):
    """Handle requests in a separate thread."""


if __name__ == '__main__':
    server = ThreadedHTTPServer(('0.0.0.0', 2000), Handler)
    print('Starting server, use <Ctrl-C> to stop')
    server.serve_forever()
