from BaseHTTPServer import HTTPServer, BaseHTTPRequestHandler
from SocketServer import ThreadingMixIn
import urlparse
import threading
import cgi
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
dbmain = client.team19Final

try:
    dbmain.command("serverStatus")

except Exception as e:
    print(e)
else:
    print("Status: Connected")

# Tables for each field
fsrTable = dbmain.fsr
tileTable = dbmain.tile
symTable = dbmain.symbol
movenumTable = dbmain.movenum
ackTable = dbmain.ack


def getdata(source):
    # Finding the most recent entry
    if (source == "FSR"):
        data = fsrTable.find_one(sort=[('_id', -1)])
    elif (source == "Sym"):
        data = symTable.find_one(sort=[('_id', -1)])
    elif (source == "Move"):
        data = movenumTable.find_one(sort=[('_id', -1)])
    elif (source == "Next"):
        data = tileTable.find_one(sort=[('_id', -1)])
    elif (source == "Ack"):
        data = ackTable.find_one(sort=[('_id', -1)])

    # Gets the Json Data
    data.pop("_id")
    data = json.dumps(data)

    # Gets the element to return
    if (source == "FSR"):
        out = data.pop("Sensor")
    elif (source == "Sym"):
        out = data.pop("Symbol")
    elif (source == "Move"):
        out = data.pop("MoveNumber")
    elif (source == "Next"):
        out = data.pop("Tile")
    elif (source == "Ack"):
        out = data.pop("Ack")

    return out


def response(jdata, source):
    out = {}
    if (source == "RoverPIC"):
        out = {}
    elif (source == "GUI"):

        out = {
            "FSR": getdata("FSR"),
            "NextLoc": getdata("Next")
            "Symbol": getdata("Sym")
            "Movement": getdata("Move")
            "Ackno": getdata("Ack")
        }
    return out


def insert(jdata, source):
    if (source == "SensorPIC"):
        # Getting the data from Json
        fsrdata = jdata.pop("Value")
        # Formatting
        fsrjson = {"Sensor": fsrdata}
        #Inserting
        fsrTable.insert(fsrjson)
    elif (source == "RoverPIC"):
        # Getting the data from Json
        ackdata = jdata.pop("Ack")
        # Formatting
        ackjson = {"Ack": ackdata}
        # Inserting
        ackTable.insert(ackjson)
    elif (source == "GUI"):
        # Getting the data from json
        symb = jdata.pop("Symbol")
        tile = jdata.pop("Tile")
        movenum = jdata.pop("MoveNumber")

        # Formatting the data to be inserted into Mongo
        symjson = {"Symbol": symb}
        tilejson = {"Tile": tile}
        monjson = {"MoveNumber": movenum}

        # Inserting the data
        symTable.insert(symjson)
        tileTable.insert(tilejson)
        movenumTable.insert(monjson)


class Handler(BaseHTTPRequestHandler):
    def do_GET(self):

        # self.close_connection = 0
        self.send_response(200)
        self.end_headers()
        message = threading.currentThread().getName()
        rawdata = str(
            self.rfile.read(int(self.headers.getheader('Content-Length'))))
        data = rawdata
        datajson = json.loads(data)
        whichpi = datajson.pop("Source")
        return

    def do_POST(self):

        return


class ThreadedHTTPServer(ThreadingMixIn, HTTPServer):
    """Handle requests in a separate thread."""


if __name__ == '__main__':
    server = ThreadedHTTPServer(('0.0.0.0', 2000), Handler)

    print('Starting server, use <Ctrl-C> to stop')
    server.serve_forever()
