#!/usr/bin/python3

import sys
import getopt



def get_cmd_help(name):
	print("%s [arguments]" % name)
	print("-i --input    : input file")
	print("-o --output   : output file")
	print("-t --template : header template file")
	print("-h --help     : get help")
	sys.exit(0)

if __name__ == "__main__":
	name = sys.argv[0]
	argv = sys.argv[1:]
	opts, args = getopt.getopt(argv, "i:o:t:h", ["input=", "output=", "template=", "help"])

	input_file    = 
	output_file   = 
	template_file = "header.txt"
	for opt, arg in opts:
		if opt in ["-i", "--input"]:
			input_file = arg
		elif opt in ["-o", "--output"]:
			output_file = arg
		elif opt in ["-t", "--template"]:
			template_file = arg
		else:
			get_cmd_help(name)