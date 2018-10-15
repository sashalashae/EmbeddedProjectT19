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
        corr_req = info[1]["Server Correct Req"] + info[2]["Server Correct Req"] + info[3]["Server Correct Req"] + info[4]["Server Correct Req"] 
        print "\t", "Correct Requests Received:", corr_req
        miss_req = info[1]["Server Missed"] + info[2]["Server Missed"] + info[3]["Server Missed"] + info[4]["Server Missed"] 
        print "\t", "Missed Requests:", miss_req
        corr_res = info[1]["Server Correct Res"] + info[2]["Server Correct Res"] + info[3]["Server Correct Res"] + info[4]["Server Correct Res"] 
        print "\t", "Correct Replies Sent:", corr_res
        inc_reply = info[1]["Server Inc Reply"] + info[2]["Server Inc Reply"] + info[3]["Server Inc Reply"] + info[4]["Server Inc Reply"] 
        print "\t", "Incorrect Replies Sent:", inc_reply
        print 50*"="

    def __del__(self):
        self.conn.close()

if __name__ == "__main__":
    print 50*"="
    server = ServerConnection("192.168.1.100", 2000)
    while(True):
        server.print_pic_info()
        time.sleep(5)
