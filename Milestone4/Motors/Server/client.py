import httplib
import json
import time
import numpy
from matplotlib import pyplot

class ServerConnection:
    def __init__(self, host, port):
        self.conn = httplib.HTTPConnection(host, port)
    
    def send_instruction(self, instruction):
        json_msg = {"Type" : "Instruction", "Content" : instruction}
        self.conn.request("POST", None, json.dumps(json_msg))
        return self.conn.getresponse().read()
    
    def get_error_data(self):
        self.conn.request("GET", None, "Errors")
        data = json.loads(self.conn.getresponse().read())
        left = numpy.array(data["Left Error"])
        right = numpy.array(data["Right Error"])
        total_left = numpy.array(data["Accumulated Left Errors"])
        total_right = numpy.array(data["Accumulated Right Errors"])
        return left, right, total_left, total_right
    
    def __del__(self):
        self.conn.close()
        
if __name__ == "__main__":
    server = ServerConnection("192.168.1.100", 2000)
    while(True):
        instruction_type = raw_input("Enter instruction type: ").upper()
        while instruction_type not in ("FORWARD", "REVERSE", "LEFT", "RIGHT", "ERRORS"):#, "STOP"):
            instruction_type = raw_input("Invalid instruction type entered. Enter instruction type: ").upper()
        #if instruction_type == "STOP":
        #    instruction = instruction_type
        if instruction_type == "ERRORS":
            left, right, total_left, total_right = server.get_error_data()
            fig, axes = pyplot.subplots(2, 2)
            time = numpy.arange(0, len(left)/10.0, 0.1)
            axes[0, 0].plot(time, left)
            axes[0, 0].set_ylabel("Left Error")
            axes[0, 1].plot(time, right)
            axes[0, 1].set_ylabel("Right Error")
            axes[1, 0].plot(time, total_left)
            axes[1, 0].set_ylabel("Accumulated Left Error")
            axes[1, 1].plot(time, total_right)
            axes[1, 1].set_ylabel("Accumulated Right Error")
            pyplot.show()
        else:
            quantity = 0
            repeat = True
            while repeat:
                quantity = raw_input("Enter the distance in cm/angle in degrees: ")
                try:
                    quantity = int(quantity)
                except ValueError:
                    print("Enter an integer.")
                    continue
                if quantity >= 0 and quantity <= 360:
                    repeat = False
                else:
                    print("Enter an integer between 0 and 360.")
            instruction = instruction_type + str(quantity).zfill(3)
            print(server.send_instruction(instruction + '\0'))
        
