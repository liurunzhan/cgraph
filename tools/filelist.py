#!/usr/bin/python3

import argparse
import os

def get_filelist_from_dir(path, suffixes, filelist):
	for root, dirs, files in os.walk(path):
		for file in files:
			if not file.startswith("."):
				file = os.path.join(root, file)
				suffix = os.path.splitext(file)[1].replace(".", "")
				if suffix in suffixes:
					filelist.append(file)
		for dir in dirs:
			if not dir.startswith("."):
				get_filelist_from_dir(os.path.join(root, dir), suffixes, filelist)

class FileList(object):
	def __init__(self, paths, suffixes):
		self.files = []
		for path in paths:
			get_filelist_from_dir(path, suffixes, self.files)
	def __repr__(self):
		return repr(self.files)
	def __str__(self):
		return str(self.files)
	def to_file(self, file, combine):
		if file == "":
			for file in self.files:
				print(file)
		else:
			with open(file, "w") as fout:
				if combine:
					print(" ".join(self.files), file=fout)
				else:
					for file in self.files:
						print(file, file=fout)

def arg_parse():
	parser = argparse.ArgumentParser(description="update C-type macro definitions", formatter_class=argparse.ArgumentDefaultsHelpFormatter)
	parser.add_argument("dirs", nargs="+", help="input directories")
	parser.add_argument("--suffix", "-s", nargs="+", required=True, dest="suffixes", help="input suffixes")
	parser.add_argument("--output", "-o", default="", help="output filelist")
	parser.add_argument("--combin", "-c", action="store_true", help="output filelist in a line of the given file")
	def func(args):
		print("find Files with Suffixes (%s) in Directories (%s)" % (" ".join(args.suffixes), " ".join(args.dirs)))
		filelist = FileList(paths=args.dirs, suffixes=args.suffixes)
		filelist.to_file(args.output, args.combine)
	parser.set_defaults(func=func)
	return parser.parse_args()
	
if __name__ == "__main__":
	args = arg_parse()
	args.func(args)