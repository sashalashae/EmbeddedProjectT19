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
collect1 = db1.pic1
collect2 = db1.pic2
collect3 = db1.pic3
collect4 = db1.pic4
piccollect1 = db1.picdata1
piccollect2 = db1.picdata2
piccollect3 = db1.picdata3
piccollect4 = db1.picdata4
gencollect = db1.gendata

pr = 0
pc = 0
pm = 0
screq = 0
sm = 0
scres = 0
sir = 0
pics_initialized = { '1' : False, '2' : False,
                     '3' : False, '4' : False }

def utf8len(s):
    return len(s.encode('utf-8'))
    
def picstats(data):
    datal = json.loads(data)
    leng = len(datal)
    whichpi = datal.pop("Source")
    print(whichpi)
    k = False
    if (collect1.count() != 0 or collect2.count() != 0
            or collect3.count() != 0 or collect4.count() != 0):
        if (whichpi == '1'):
            res = collect1.find_one(sort=[('_id', -1)])
            k = True
        elif (whichpi == '2'):
            res = collect2.find_one(sort=[('_id', -1)])
            k = True
        elif (whichpi == '3'):
            res = collect3.find_one(sort=[('_id', -1)])
            k = True
        elif (whichpi == '4'):
            res = collect4.find_one(sort=[('_id', -1)])
            k = True
        if k == True:
            res.pop('_id')
            opr = res.pop("Expected")
            opc = res.pop("PIC Correct")
            opm = res.pop("PIC Missed")
            oscreq = res.pop("Server Correct Req")
            osm = res.pop("Server Missed")
            oscres = res.pop("Server Correct Res")
            osir = res.pop("Server Inc Reply")
            temprid = int(datal.pop("RID"))
            if not pics_initialized[whichpi]:
                pics_initialized[whichpi] = True
                opr = temprid
            diff = abs(int(temprid)-int(opr))
            err = "None"
            if (diff > 1):
                opm = diff + opm
                osm = osm + diff
                opr = int(temprid) + 1
                err = "Missed Request"
            else:
                opc = opc + 1
                oscreq = oscreq + 1
                oscres = oscres + 1
                opr = opr + 1
            nstats = {
                "PIC Requests": opc+opm,
                "PIC Correct": opc,
                "PIC Missed": opm,
                "Server Correct Req": oscreq,
                "Server Missed": osm,
                "Server Correct Res": oscres,
                "Server Inc Reply": osir,
                "Expected": opr                                                
            }
            if (whichpi == '1'):
                collect1.insert(nstats)
            elif (whichpi == '2'):
                collect2.insert(nstats)
            elif (whichpi == '3'):
                collect3.insert(nstats)
            elif (whichpi == '4'):
                collect4.insert(nstats)
    else:
        instats = {
            "_id": 1,
            "PIC Requests": 1,
            "PIC Correct": pc,
            "PIC Missed": pm,
            "Server Correct Req": screq,
            "Server Missed": sm,
            "Server Correct Res": scres,
            "Server Inc Reply": sir
        }
        collect1.insert(instats)
        collect2.insert(instats)
        collect3.insert(instats)
        collect4.insert(instats)

def insertdata(data):
    datal = json.loads(data)
    whichpi = datal.pop("Source")
    storedata = datal.pop("Key")
    pidata = {
        "Value":storedata
        }
    if (whichpi == '1'):
        piccollect1.insert(pidata)
    elif (whichpi == '2'):
        piccollect2.insert(pidata)
    elif (whichpi == '3'):
        piccollect3.insert(pidata)
    elif (whichpi == '4'):
        piccollect4.insert(pidata)
    
def getdata(data):
    datal = json.loads(data)
    whichpi = datal.pop("Source")
    if (collect1.count() != 0 or collect2.count() != 0
        or collect3.count() != 0 or collect4.count() != 0):
            dbdata1 = piccollect1.find_one(sort=[('_id', -1)])
            dbdata2 = piccollect2.find_one(sort=[('_id', -1)])
            dbdata3 = piccollect3.find_one(sort=[('_id', -1)])
            dbdata4 = piccollect4.find_one(sort=[('_id', -1)])
            dbdata1.pop("_id")
            dbdata2.pop("_id")
            dbdata3.pop("_id")
            dbdata4.pop("_id")
            dbdata1 = json.dumps(dbdata1)
            dbdata2 = json.dumps(dbdata2)
            dbdata3 = json.dumps(dbdata3)
            dbdata4 = json.dumps(dbdata4)
            whichpi = json.dumps(whichpi)
            outdata ={
                "Source Pic": whichpi,
                "Pic 1": dbdata1,
                "Pic 2": dbdata2,
                "Pic 3": dbdata3,
                "Pic 4": dbdata4
            }
    return outdata

class Handler(BaseHTTPRequestHandler):
    def do_GET(self):
        #self.close_connection = 0
        self.send_response(200)
        self.end_headers()
        message = threading.currentThread().getName()
        rawdata = str(
            self.rfile.read(int(self.headers.getheader('Content-Length'))))
        data, checksum = rawdata.rsplit("}")
        data += "}"
        copydata = data
        datal = json.loads(data)
        whichpi = datal.pop("Source")
        whichmsg = datal.pop("MsgType")
        if (whichmsg == 'Stat'):
            if (whichpi == '1'):
                res = collect1.find_one(sort=[('_id', -1)])
                res.pop('_id')
            elif (whichpi == '2'):
                res = collect2.find_one(sort=[('_id', -1)])
                res.pop('_id')
            elif (whichpi == '3'):
                res = collect3.find_one(sort=[('_id', -1)])
                res.pop('_id')
            elif (whichpi == '4'):
                res = collect4.find_one(sort=[('_id', -1)])
                res.pop('_id')
            stats = {
                "PIC Requests": res.pop("PIC Requests"),
                "PIC Correct": res.pop("PIC Correct"),
                "PIC Missed": res.pop("PIC Missed"),
                "Server Correct Req": res.pop("Server Correct Req"),
                "Server Missed": res.pop("Server Missed"),
                "Server Correct Res": res.pop("Server Correct Res"),
                "Server Inc Reply": res.pop("Server Inc Reply")
            }
            self.wfile.write(stats)
        elif (whichmsg == "Value"):
            picstats(data)
            output = getdata(copydata)
            self.wfile.write(output)
        return

    def do_POST(self):
        # self.close_connection = 0
        self.send_response(200)
        self.end_headers()
        rawdata = str(
                    self.rfile.read(int(self.headers.getheader('Content-Length'))))
        data, checksum = rawdata.rsplit("}")
        data += "}"
        picstats(data)
        insertdata(data)
        out = {
            "Response":"Added to db"
            }
        self.wfile.write(out)
        return


class ThreadedHTTPServer(ThreadingMixIn, HTTPServer):
    """Handle requests in a separate thread."""


if __name__ == '__main__':
    instats={
                "PIC Requests": pr,
                "PIC Correct": pc,
                "PIC Missed": pm,
                "Server Correct Req": screq,
                "Server Missed": sm,
                "Server Correct Res": scres,
                "Server Inc Reply": sir,
                "Expected": pr
            }
    pidata = {
    "Value":pr
    }
    piccollect1.insert(pidata)
    piccollect2.insert(pidata)
    piccollect3.insert(pidata)
    piccollect4.insert(pidata)
    collect1.insert(instats)
    collect2.insert(instats)
    collect3.insert(instats)
    collect4.insert(instats)
    server = ThreadedHTTPServer(('0.0.0.0', 2000), Handler)
    
    print('Starting server, use <Ctrl-C> to stop')
    server.serve_forever()
