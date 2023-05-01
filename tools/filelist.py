#!/usr/bin/python3

import argparse
import os
try:
	from collections.abc import Iterable
except ImportError:
  from collections import Iterable

def flatten(items):
  for item in items:
    if isinstance(item, Iterable) and not isinstance(item, str):
      for subitem in flatten(item):
        yield subitem
    else:
      yield item

def extend(items):
  return [item for item in flatten(items=items)]

def get_filelist_from_dir(path, suffixes, ignore_files, ignore_dirs, ignore_paths, filelist):
  for item in os.scandir(path):
    if item.is_file() and not item.is_symlink():
      if item.name.startswith(".") or item.name in ignore_files or item.path in ignore_paths or os.path.splitext(item.path)[1].replace(".", "") not in suffixes:
        continue
      filelist.append(item.path)
    elif item.is_dir():
      if item.name.startswith(".") or item.name in ignore_dirs or item.path in ignore_paths:
        continue
      get_filelist_from_dir(path=item.path, suffixes=suffixes, ignore_files=ignore_files, ignore_dirs=ignore_dirs, ignore_paths=ignore_paths, filelist=filelist)

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
  parser.add_argument("dirs", nargs="+", type=str, help="input directories")
  parser.add_argument("-s", "--suffix", nargs="+", required=True, dest="suffixes", type=str, action="append", help="input suffixes")
  parser.add_argument("-if", "--ignore_files", nargs="+", default=[], dest="ignore_files", type=str, action="append", help="ignore file names")
  parser.add_argument("-id", "--ignore_dirs", nargs="+", default=[], dest="ignore_dirs", type=str, action="append", help="ignore directory names")
  parser.add_argument("-ip", "--ignore_paths", nargs="+", default=[], dest="ignore_paths", type=str, action="append", help="ignore path names")
  parser.add_argument("-o", "--output", default="", type=str, help="output filelist")
  parser.add_argument("-t", "--output_type", default="filelist", choices=["filelist", "csv", "md"], type=str, help="output filelist type")
  parser.add_argument("-c", "--combine", action="store_true", help="output filelist in a line of the given file")
  parser.add_argument("-p", "--prefix", default="", type=str, help="prefix of each file path")
  def func(args):
    suffixes = extend(args.suffixes)
    ignore_files = extend(args.ignore_files)
    ignore_dirs = extend(args.ignore_dirs)
    ignore_paths = extend(args.ignore_paths)
    dirs = extend(args.dirs)
    print("find Files with Suffixes (%s) and without Names (%s) in Directories (%s)" % (" ".join(suffixes), " ".join(ignore_files), " ".join(dirs)))
    filelist = FileList(paths=dirs, suffixes=suffixes, ignore_files=ignore_files, ignore_dirs=ignore_dirs, ignore_paths=ignore_paths)
    filelist.to_file(file=args.output, combine=args.combine, type=args.output_type)
  parser.set_defaults(func=func)
  return parser.parse_args()
  
if __name__ == "__main__":
  args = arg_parse()
  args.func(args)