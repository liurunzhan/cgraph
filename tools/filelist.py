#!/usr/bin/python3

import argparse
import os

def get_filelist_from_dir(path, suffixes, ignore_files, ignore_dirs, ignore_paths, filelist):
	for root, dirs, files in os.walk(path):
		for file in files:
			if file.startswith(".") or file in ignore_files:
				continue
			file = os.path.join(root, file)
			suffix = os.path.splitext(file)[1].replace(".", "")
			if suffix not in suffixes or file in ignore_paths:
				continue
			filelist.append(file)
		for dir in dirs:
			if dir.startswith(".") or dir in ignore_dirs:
				continue
			subpath = os.path.join(root, dir)
			if subpath not in ignore_paths:
				continue
			get_filelist_from_dir(path=subpath, suffixes=suffixes, ignore_files=ignore_files, ignore_dirs=ignore_dirs, ignore_paths=ignore_paths, filelist=filelist)

class FileList(object):
	def __init__(self, paths, suffixes, ignore_files, ignore_dirs, ignore_paths):
		self.files = []
		for path in paths:
			get_filelist_from_dir(path=path, suffixes=suffixes, ignore_files=ignore_files, ignore_dirs=ignore_dirs, ignore_paths=ignore_paths, filelist=self.files)
	def __len__(self):
		return len(self.files)
	def __repr__(self):
		return repr(self.files)
	def __str__(self):
		return str(self.files)
	def to_terminal(self, combine):
		if combine:
			print(" ".join(self.files))
		else:
			for file in self.files:
				print(file)
	def to_filelist(self, file, combine):
		with open(file, "w") as fout:
			if combine:
				print(" ".join(self.files), file=fout)
			else:
				for file in self.files:
					print(file, file=fout)
	def to_csv(self, file, combine):
		with open(file, "w") as fout:
			if combine:
				print(",".join(self.files), file=fout)
			else:
				print("file,path", file=fout)
				for file in self.files:
					print("{basename},{dirname}".format(basename=os.path.basename(file), dirname=os.path.dirname(file)), file=fout)
	def to_markdown(self, file, combine):
		with open(file, "w") as fout:
			if combine:
				print("|%s|" % ("|".join([" "] * len(self))), file=fout)
				print("|%s|" % ("|".join([" :-: "] * len(self))), file=fout)
				print("|%s|" % ("|".join(self.files)), file=fout)
			else:
				print("| file | path |", file=fout)
				print("| :-: | :-: |", file=fout)
				for file in self.files:
					print("| {basename} | {dirname} |".format(basename=os.path.basename(file), dirname=os.path.dirname(file)), file=fout)
	def to_file(self, file, combine, type):
		if file == "":
			self.to_terminal(file)
		elif type == "filelist":
			self.to_filelist(file, combine)
		elif type == "csv":
			self.to_csv(file, combine)

def arg_parse():
	parser = argparse.ArgumentParser(description="update C-type macro definitions", formatter_class=argparse.ArgumentDefaultsHelpFormatter)
	parser.add_argument("dirs", nargs="+", help="input directories")
	parser.add_argument("--suffix", "-s", nargs="+", required=True, dest="suffixes", help="input suffixes")
	parser.add_argument("--ignore_files", "-if", nargs="+", default=[], dest="ignore_files", help="ignore file names")
	parser.add_argument("--ignore_dirs", "-id", nargs="+", default=[], dest="ignore_dirs", help="ignore directory names")
	parser.add_argument("--ignore_paths", "-ip", nargs="+", default=[], dest="ignore_paths", help="ignore path names")
	parser.add_argument("--output", "-o", default="", help="output filelist")
	parser.add_argument("--output_type", "-t", default="filelist", choices=["filelist", "csv", "md"], help="output filelist type")
	parser.add_argument("--combine", "-c", action="store_true", help="output filelist in a line of the given file")
	def func(args):
		print("find Files with Suffixes (%s) and without Names (%s) in Directories (%s)" % (" ".join(args.suffixes), " ".join(args.ignore_files), " ".join(args.dirs)))
		filelist = FileList(paths=args.dirs, suffixes=args.suffixes, ignore_files=args.ignore_files, ignore_dirs=args.ignore_dirs, ignore_paths=args.ignore_paths)
		filelist.to_file(file=args.output, combine=args.combine, type=args.output_type)
	parser.set_defaults(func=func)
	return parser.parse_args()
	
if __name__ == "__main__":
	args = arg_parse()
	args.func(args)