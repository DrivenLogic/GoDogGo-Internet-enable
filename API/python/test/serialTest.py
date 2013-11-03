#!/usr/bin/env python

import serial

s = serial.Serial(port='/dev/ttyUSB0', baudrate=9600)

s.write('T')
s.read()
s.readline()

