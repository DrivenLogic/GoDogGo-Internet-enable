#!/usr/bin/env python

# Usage: GDG.throw.cmd.py /dev/[yourSerialAdaptor]
#
# NB: 	under linux it will be somthing like /dev/ttyUSB0 on a mac /dev/cu.PL2303-00001014 
# 	To locate your adaptor try #ls /dev/ttyUSB* -or- #ls /dev/cu.* respectively)

import sys
import serial

def main():	
        print('hello serial!')
  	print('sys.argv[1]')


def processSerialResponse():
	s = serial.Serial(port='sys.argv[1]', baudrate=9600)
	
    	#if :
        #	return True
    	#else:
        #	return False


# send the Throw command


# parse the result. 
# cast to a bool like value.

