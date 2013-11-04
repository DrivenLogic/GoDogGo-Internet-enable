#!/usr/bin/env python

import sys
import serial

s = serial.Serial(port=sys.argv[1], baudrate=9600)

# send throw command
s.write('T')

# read results 
# T1 = the throw operation was accepted 
# T0 = the throw command could not be completed
result = s.readline();
#print(result)

if result == "T1":
    print ("true")
else:
    print ("false")
