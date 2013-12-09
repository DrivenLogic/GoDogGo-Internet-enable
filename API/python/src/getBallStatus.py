#!/usr/bin/env python

import sys
import serial
import time

result = '-2'

for x in range(0, 5):
	try:
		s = serial.Serial(port=sys.argv[1], baudrate=9600)
		
		# send throw command
		s.write('B')
		
		# read results 
		# B1 = A ball is present ready for a throw
		# B0 = A ball is not present 
		result = s.readline()
		result = result.strip()
		#print(result)
		
		s.close()
		
		if result == 'B1':
			result = '1'
		else:
			result = '0'
		
	except:
		 result = '-1'
		 time.sleep(2)
		 
print(result)