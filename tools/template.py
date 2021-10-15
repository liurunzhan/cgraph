#!/usr/bin/env python3

import argparse
import os

class Macro(object):
	def __init__(self, macro, definition) -> None:
		super().__init__()
		self.macro = macro
		self.definition = definition

class MacroFunction(Macro):
	def __init__(self, macro, definition, arguments) -> None:
		super().__init__(macro, definition)
		self.arguments = arguments

def parse_template_header_file(file, type):
	lines = None
	with open(file, "r") as fin:
		lines = fin.readlines()
	string = ""
	for line in lines:
		if line.endswith("\\"):
			string += line
		elif line.startswith("#define"):
			string = line
		else:
			string = ""

	return lines

def cmd_arg_parse(project):
	parser = argparse.ArgumentParser(description="parse template C header file and source file in PROJECT %s" % (project))
	parser.add_argument("--include-dir", type=str, help="included header file directory")
	parser.add_argument("--source-dir", type=str, help="source file directory")
	parser.add_argument("--common-header-file", type=str, help="common-defined template header file")
	parser.add_argument("--self-header-file", type=str, help="self-defined template header file")
	parser.add_argument("--source-file", type=str, help="source file")

	return parser.parse_args()


if __name__ == "__main__":
	project = "cgraph"
	args = cmd_arg_parse(project=project)
	args.func(args)