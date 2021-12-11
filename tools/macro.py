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
		self.group = group
		self.macros = []
	def __str__(self):
		macros = ["/** %s */" % self.group]
		for macro in self.macros:
			macros.append(macro)
		return "\n".join(macros)
	def __repr__(self):
		return str(self)
	def append(self, macro, template):
		self.macros.append(template.format(macro=macro))

class MacroList(object):
	def __init__(self):
		self.groups = []
	def __str__(self):
		return str(self.groups)
	def __repr__(self):
		return repr(self.groups)
	def __getitem__(self, index):
		return self.groups[index]
	def __setitem__(self, index, item):
		self.groups[index] = item
	def append(self, group):
		self.groups.append(group)

class MacroState(Enum):
	IDLE = 0
	DOCS = 1
	MACRO = 2
	ENTRY = 3

macro_start_mode = r"/\*{4,}$"
macro_group_mode = r"MACRO GROUP : (.*)"
macro_split_mode = r"[ \r\t]+"
macro_end_mode = r"\*{4,}/$"

def read_macro_by_file(file, template):
	state = MacroState.IDLE
	macros = MacroList()
	headers = []
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
			if state == MacroState.IDLE:
				if re.search(macro_start_mode, line):
					state = MacroState.DOCS
			elif state == MacroState.DOCS:
				if re.search(macro_group_mode, line):
					state = MacroState.MACRO
					group = re.findall(macro_group_mode, line)[0]
					macros.append(Macro(group=group))
			elif state == MacroState.MACRO:
				if re.search(macro_end_mode, line):
					headers.append(line)
					state = MacroState.ENTRY
			if state == MacroState.IDLE or state == MacroState.DOCS or state == MacroState.MACRO:
				headers.append(line)
	return macros, headers

def arg_parse():
	parser = argparse.ArgumentParser(description="update C-type macro definitions")
	parser.add_argument("file", help="input file")
	parser.add_argument("-t", "--template", required=True, help="template macro file")
	parser.add_argument("-c", "--comment", required=True, help="comment in the end of file")
	def func(args):
		template = read_template_by_file(file=args.template)
		macros, headers = read_macro_by_file(file=args.file, template=template)
		with open(args.file, "w") as fout:
			for line in headers:
				print(line, file=fout)
			print("", file=fout)
			for macro in macros:
				print(macro, file=fout)
			print("/** %s */" % args.comment, file=fout)
	parser.set_defaults(func=func)
	return parser.parse_args()

if __name__ == "__main__":
	args = arg_parse()
	args.func(args)