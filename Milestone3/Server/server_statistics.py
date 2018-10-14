import httplib
import json
import time

class ServerConnection:
    def __init__(self, host, port):
        self.conn = httplib.HTTPConnection(host, port)

    def _get_pic_info(self, pic_number):
        if pic_number not in (1, 2, 3, 4):
            print("Invalid PIC number")
            return
        msg = { "MsgType" : "Stat", "Source" : str(pic_number) }
        self.conn.request("GET", None, json.dumps(msg))
        text = self.conn.getresponse().read().replace("'",'"')
        info = json.loads(text)
        return info

    def _get_all_pic_info(self):
        info = {}
        info[1] = self._get_pic_info(1)
        info[2] = self._get_pic_info(2)
        info[3] = self._get_pic_info(3)
        info[4] = self._get_pic_info(4)
        return info

    def print_pic_info(self):
        info = self._get_all_pic_info()
        for pic_number in info.keys():
            print "Statisics for PIC", pic_number
            print "\t", "Requests Sent:", info[pic_number]["PIC Requests"]
            print "\t", "Correct Replies Received:", info[pic_number]["PIC Correct"]
            print "\t", "Missed Replies:", info[pic_number]["PIC Missed"], "\n"
        print "Server Statistics"
        print "\t", "Correct Requests Received:", info[1]["Server Correct Req"]
        print "\t", "Missed Requests:", info[1]["Server Missed"]
        print "\t", "Correct Replies Sent:", info[1]["Server Correct Res"]
        print "\t", "Incorrect Replies Sent:", info[1]["Server Inc Reply"]
        print 50*"="

    def __del__(self):
        self.conn.close()

if __name__ == "__main__":
    print 50*"="
    server = ServerConnection("192.168.1.100", 2000)
    while(True):
        server.print_pic_info()
        time.sleep(5)
