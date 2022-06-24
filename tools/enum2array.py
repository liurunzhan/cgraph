#!/usr/bin/python3

import argparse
from collections import OrderedDict
import re

def read_source_by_file(file):
	template = None
	with open(file, "r") as fin:
		template = fin.read()
	return template

VARIABE_MODE = re.compile(r"(\w*)\s*=\s*(\w*)\s*,?\s*/\*\*<\s*(\w*)\s+(\w*)\s*:\s*(\w+)", re.S)

def gen_enum_match_mode(enum_name):
	return re.compile(r"enum\s*\{(.*?)\}\s*%s\s*;"%(enum_name), re.S)

def gen_arrary_match_mode(array_name):
	return re.compile(r"static const cgraph_char_t \*%s(.*?);"%(array_name), re.S)

ITEM_FIRST_MODE = "\"{cname}\", /**< {dmode} {dtype} : {dname} */"
ITEM_LAST_MODE = "\"{cname}\" /**< {dmode} {dtype} : {dname} */"

class Variable(object):
	def __init__(self, item, last):
		self.cname = item[0]
		self.ctype = item[1]
		self.dmode = item[2]
		self.dtype = " " + item[3] if len(item[3]) == 1 else item[3]
		self.dname = item[4]
		self.clast = last
	def __str__(self):
		if self.clast:
			return ITEM_LAST_MODE.format(cname=self.cname, ctype=self.ctype, dmode=self.dmode, dtype=self.dtype, dname=self.dname)
		else:
			return ITEM_FIRST_MODE.format(cname=self.cname, ctype=self.ctype, dmode=self.dmode, dtype=self.dtype, dname=self.dname)
	def __repr__(self):
		return str(self)
	def __eq__(self, other):
		return self.cname == other.cname and self.ctype == other.ctype and self.dmode == other.dmode and self.dtype == other.dtype and self.dname == other.dname
	def __hash__(self):
		return hash(self.cname)

class VariableList(object):
	def __init__(self):
		self.variables = OrderedDict()
	def append(self, item, last):
		variable = Variable(item, last)
		if variable.ctype not in self.variables:
			self.variables[variable.ctype] = []
		self.variables[variable.ctype].append(variable)
	def to_list(self):
		data = []
		for type in self.variables:
			cname = []
			ctype = None
			dmode = None
			dtype = []
			dname = []
			for item in self.variables[type]:
				if len(cname) <= 0 or cname[-1] != item.cname:
					cname.append(item.cname)
				ctype = item.ctype
				dmode = item.dmode
				if len(dtype) <= 0 or dtype[-1] != item.dtype:
					dtype.append(item.dtype)
				if len(dname) <= 0 or dname[-1] != item.dname:
					dname.append(item.dname)
			data.append(Variable(["/".join(cname), ctype, dmode, "/".join(dtype), "/".join(dname)], False))
		if len(data) > 0:
			data[-1].clast = True
		return data
	def to_source(self, array):
		data = self.to_list()
		data = [str(item) for item in data]
		data.insert(0, "static const cgraph_char_t *%s[] = {" % (array))
		data.append("};")
		return "\n".join(data)
	def __str__(self):
		data = self.to_list()
		strs = [str(item) for item in data]
		return "\n".join(strs)
	def __repr__(self):
		return str(self)
	def set_last_true(self):
		pass

def arg_parse():
	parser = argparse.ArgumentParser(description="update C-type enum definitions", formatter_class=argparse.ArgumentDefaultsHelpFormatter)
	parser.add_argument("header", type=str, help="parsed file")
	parser.add_argument("-e", "--enum", required=True, type=str, help="input C-type enum name")
	parser.add_argument("-s", "--source", required=True, type=str, help="input C-type source file")
	parser.add_argument("-a", "--array", required=True, type=str, help="input C-type array name")
	parser.add_argument("-o", "--output", default="", type=str, help="output C-type source file")
	def func(args):
		header = read_source_by_file(args.header)
		source = read_source_by_file(args.source)
		enum_mode = gen_enum_match_mode(args.enum)
		array_mode = gen_arrary_match_mode(args.array)
		variables = VariableList()
		for line in re.findall(enum_mode, header):
			for item in re.findall(VARIABE_MODE, line):
				variables.append(item=item, last=False)
		for line in re.findall(array_mode, source):
			line = "static const cgraph_char_t *%s%s;" % (args.array, line)
			print(line)
			source = source.replace(line, variables.to_source(array=args.array))
		if args.output == "":
			print(source, end="")
		else:
			with open(args.source, "w") as fout:
				print(source, file=fout, end="")

	parser.set_defaults(func=func)
	return parser.parse_args()


if __name__ == "__main__":
	args = arg_parse()
	args.func(args)