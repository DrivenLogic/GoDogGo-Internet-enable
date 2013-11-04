===============================================================================
GDG - Basic command line python scripts

--------------------------------
Usage: 	GDG.[command].cmd.py /dev/[SerialAdaptorLocation]

Example:

	$ ./GDG.throw.cmd.py /dev/ttyUSB0
	false
	
	(issues the result of the command as a boolean string)

NOTE: 	
	On OSX it may be somthing like /dev/cu.PL2303-00001014 
 	To locate your adaptor try #ls /dev/cu.* 
