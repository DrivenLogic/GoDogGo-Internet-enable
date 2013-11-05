===============================================================================
GDG - Basic command line python scripts

--------------------------------
Usage: 	GDG.[command].cmd.py /dev/[SerialAdaptorLocation]

Example:

	$ ./GDG.throw.cmd.py /dev/ttyUSB0

	- issues the result of the command as a boolean string

	$ ./watch -d -n10 ./GDG.throw.cmd.py /dev/ttyUSB0

	- will throw the ball every 10 seconds, see: man watch

NOTE: 	
	On OSX the serial adaptor location may be somthing like /dev/cu.PL2303-00001014 
 	To locate your adaptor try #ls /dev/cu.* 
