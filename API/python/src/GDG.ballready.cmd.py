#!/usr/bin/env python

import sys
import serial

s = serial.Serial(port=sys.argv[1], baudrate=9600)

# send throw command
s.write('B')

# read results 
# B1 = A ball is present ready for a throw
# B0 = A ball is not present 
result = s.readline();
#print(result)

if result == "B1":
    print ("true")
else:
    print ("false")
