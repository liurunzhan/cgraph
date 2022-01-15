#!/usr/bin/python3

import argparse
import os

def get_filelist_from_dir(path, suffixes, filelist):
	for root, dirs, files in os.walk(path):
		for file in files:
			suffix = file.split(".")
			suffix = suffix[-1] if len(suffix) > 1 else ""
			if not file.startswith(".") and suffix in suffixes:
				subpath = os.path.join(path, file)
				filelist.append(subpath)
		for dir in dirs:
			if not dir.startswith("."):
				subpath = os.path.join(path, dir)
				get_filelist_from_dir(subpath, suffixes, filelist)

class FileList(object):
	def __init__(self, paths, suffixes):
		self.files = []
		for path in paths:
			get_filelist_from_dir(path, suffixes, self.files)
	def __repr__(self):
		return repr(self.files)
	def __str__(self):
		return str(self.files)
	def to_file(self, file):
		with open(file, "w") as fout:
			for file in self.files:
				print(file, file=fout)

def arg_parse():
	parser = argparse.ArgumentParser(description="update C-type macro definitions", formatter_class=argparse.ArgumentDefaultsHelpFormatter)
	parser.add_argument("dirs", nargs="+", help="input directories")
	parser.add_argument("-s", "--suffix", required=True, dest="suffixes", action="append", help="input suffixes")
	parser.add_argument("-o", "--output", required=True, help="output filelist")
	def func(args):
		filelist = FileList(paths=args.dirs, suffixes=args.suffixes)
		filelist.to_file(args.output)
	parser.set_defaults(func=func)
	return parser.parse_args()
	
if __name__ == "__main__":
	args = arg_parse()
	args.func(args)