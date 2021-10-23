#!/usr/bin/python3

import os
import re
import argparse
from enum import Enum

macro_template = """#ifdef {macro}
#undef {macro}
#endif
"""

class Macro(object):
	def __init__(self, group):
		self.group = group
		self.macros = []
	def __str__(self):
		macros = ["/** %s */" % self.group]
		for macro in self.macros:
			macros.append(macro_template.format(macro=macro))
		return "\n".join(macros)
	def __repr__(self):
		return str(self)
	def append(self, macro):
		self.macros.append(macro)

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

def read_macro_by_file(file):
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
							macros[-1].append(macro)
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
	parser = argparse.ArgumentParser(description="")
	parser.add_argument("ifile", help="input file")
	parser.add_argument("ofile", help="output file")
	def func(args):
		macros, headers = read_macro_by_file(args.ifile)
		with open(args.ofile, "w") as fout:
			for line in headers:
				print(line, file=fout)
			print("", file=fout)
			for macro in macros:
				print(macro, file=fout)
			print("/** end of cgraph_template_off */", file=fout)
	parser.set_defaults(func=func)
	return parser.parse_args()

if __name__ == "__main__":
	args = arg_parse()
	args.func(args)