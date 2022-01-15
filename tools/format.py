#!/usr/bin/python3

import argparse
import re

def line_parser(file, mode):
	if mode == "win":
		line_end = "\r\n"
	elif mode == "unix":
		line_end = "\n"
	elif mode == "macos":
		line_end = "\r"
	no_empty_line = 0
	with open(file, "r") as fin:
		lines = []
		i = 0
		for line in fin.readlines():
			i += 1
			line = line.rstrip("\n").rstrip("\r")
			if not line.isspace() and line != "":
				no_empty_line = i
			lines.append(line + line_end)
	with open(file, "w") as fout:
		for i in range(0, no_empty_line):
			print(lines[i], file=fout, end="")

def arg_parse():
	parser = argparse.ArgumentParser(description="update file style", formatter_class=argparse.ArgumentDefaultsHelpFormatter)
	parser.add_argument("files", nargs="+", help="parsed source files")
	parser.add_argument("-m", "--mode", required=True, choices=["win", "unix", "macos"], help="input suffixes")
	def func(args):
		for file in args.files:
			line_parser(file, mode=args.mode)
	parser.set_defaults(func=func)
	return parser.parse_args()

if __name__ == "__main__":
	args = arg_parse()
	args.func(args)