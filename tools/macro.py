#!/usr/bin/python3

import os
import re
import argparse
from enum import Enum

def read_template_by_file(file):
	template = None
	with open(file, "r") as fin:
		template = fin.read()
	
	return template

class Macro(object):
	def __init__(self, group):
		self.group     = group
		self.macros    = []
		self.variables = []
	def __str__(self):
		macros = ["/** %s */" % self.group]
		for macro in self.macros:
			macros.append(macro)
		return "\n".join(macros)
	def __repr__(self):
		return str(self)
	def append(self, macro, template):
		self.macros.append(template.format(macro=macro))
		self.variables.append(macro)

class MacroList(object):
	def __init__(self):
		self.groups = []
	def __str__(self):
		return str(self.groups)
	def __repr__(self):
		return repr(self.groups)
	def __len__(self):
		return len(self.groups)
	def __getitem__(self, index):
		return self.groups[index]
	def __setitem__(self, index, item):
		self.groups[index] = item
	def append(self, group):
		self.groups.append(group)

class MacroState(Enum):
	IDLE  = 0
	DOCS  = 1
	MACRO = 2
	ENTRY = 3
	END   = 4

macro_start_mode = re.compile(r"/\*{8,}$")
macro_group_mode = re.compile(r"MACRO GROUP : (.*)")
macro_split_mode = re.compile(r"[ \r\t]+")
macro_end_mode   = re.compile(r"\*{8,}/$")
macro_fend_mode  = re.compile(r"#ifdef __cplusplus")

def read_macro_by_file(file, template):
	state = MacroState.IDLE
	macros = MacroList()
	headers = []
	ends = []
	with open(file, "r") as fin:
		for line in fin.readlines():
			line = line.rstrip()
			if state == MacroState.MACRO:
				if re.search(macro_group_mode, line):
					group = re.findall(macro_group_mode, line)[0]
					macros.append(Macro(group=group))
				else:
					for macro in re.split(macro_split_mode, line):
						if macro != "" and macro != "*" and not re.search(macro_end_mode, macro):
							macros[-1].append(macro, template=template)
			if state == MacroState.IDLE and re.search(macro_start_mode, line):
				state = MacroState.DOCS
			elif state == MacroState.DOCS and re.search(macro_group_mode, line):
				state = MacroState.MACRO
				group = re.findall(macro_group_mode, line)[0]
				macros.append(Macro(group=group))
			elif state == MacroState.MACRO and re.search(macro_end_mode, line):
				headers.append(line)
				state = MacroState.ENTRY
			elif state == MacroState.ENTRY and re.search(macro_fend_mode, line):
				state = MacroState.END
			if state == MacroState.IDLE or state == MacroState.DOCS or state == MacroState.MACRO:
				headers.append(line)
			elif state == MacroState.END:
				ends.append(line)
	return macros, headers, ends

def arg_parse():
	parser = argparse.ArgumentParser(description="update C-type macro definitions", formatter_class=argparse.ArgumentDefaultsHelpFormatter)
	parser.add_argument("file", help="parsed file")
	parser.add_argument("-t", "--template", required=True, help="template macro file")
	parser.add_argument("-c", "--comment", required=True, help="comment in the end of file")
	parser.add_argument("-o", "--output", default="", help="output file")
	parser.add_argument("--novar", action="store_false", help="do not add macro variables to file")
	def func(args):
		template = read_template_by_file(file=args.template)
		macros, headers, ends = read_macro_by_file(file=args.file, template=template)
		output = args.output if args.output != "" else args.file
		with open(output, "w") as fout:
			for line in headers:
				print(line, file=fout)
			if len(macros) > 0:
				if args.novar:
					print("", file=fout)
					print("/*", file=fout)
					print("  defined macro variables:", file=fout)
					for macro in macros:
						for variable in macro.variables:
							print("  #define %s" % variable, file=fout)
					print("*/", file=fout)
				print("", file=fout)
				for macro in macros:
					print(macro, file=fout)
			if args.comment != "":
				print("/** %s */" % args.comment, file=fout)
			for end in ends:
				print(end, file=fout)
	parser.set_defaults(func=func)
	return parser.parse_args()

if __name__ == "__main__":
	args = arg_parse()
	args.func(args)