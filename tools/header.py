#!/usr/bin/env python3

import argparse
import time
import sys
import os
import json

def parse_project(file):
	project = None
	with open(file, "r") as fin:
		project = json.loads(fin.read())
	if "package" not in project or project["package"] == "":
		project["package"] = "cgraph"
	if "author" not in project or project["author"] == "":
		project["author"] = "liurunzhan"
	if "email" not in project or project["email"] == "":
		project["email"] = "liurunzhan@sina.com"
	if "date" not in project or project["date"] == "":
		project["date"] = time.strftime("%Y-%m-%d", time.localtime())
	if "lisence" not in project or project["lisence"] == "":
		project["lisence"] = "GPL-3.0"
	if "version" not in project or project["version"] == "":
		project["version"] = "0.0.0"
	
	return project

def parse_brief(file):
	intro = None
	with open(file, "r") as fin:
		intro = json.loads(fin.read())

	return intro

def parse_template(template, file, project, brief):
	basename = os.path.basename(file)
	if basename not in brief:
		print("%s not in brief file %s" % (basename, args.brief))
		sys.exit(0)
	lines = []
	with open(template, "r") as fin:
		for line in fin.readlines():
			line = line.rstrip()
			if "@file" in line:
				line = line.replace("${FILE}", basename if not basename.endswith(".in") else basename.rstrip(".in"))
			if "@package" in line:
				line = line.replace("${PACKAGE}", project["package"])
			if "@version" in line:
				line = line.replace("${VERSION}", project["version"])
			if "@author" in line:
				line = line.replace("${AUTHOR}", project["author"])
			if "@email" in line:
				line = line.replace("${EMAIL}", project["email"])
			if "@date" in line:
				line = line.replace("${DATE}", project["date"])
			if "@lisence" in line:
				line = line.replace("${LISENCE}", project["lisence"])
			if "@brief" in line:
				line = line.replace("${BRIEF}", brief[basename])
			lines.append(line)
	
	return lines

def delete_header_from_file(file):
	lines = []
	flag = False
	cnt = 0
	with open(file, "r") as fin:
		for line in fin.readlines():
			line = line.replace("\r", "").replace("\n", "")
			lines.append(line)
	if lines[0].startswith("/**") and not lines[0].endswith("*/") and "*/" not in lines[0]:
		for line in lines[:]:
			if line.startswith(" */") or line.startswith("*/"):
				lines.remove(line)
				break
			lines.remove(line)
	
	return lines

def add_template_to_file(lines, template):
	if lines[0].startswith("/**"):
		return template + lines
	elif lines[0] == "":
		return template + lines
	else:
		return template + [""] + lines

def write_lines_to_file(lines, file):
	with open(file, "w") as fout:
		for line in lines:
			print(line, file=fout)

def arg_parse():
	parser = argparse.ArgumentParser(description="update C-type macro definitions")
	parser.add_argument("file", help="source file")
	parser.add_argument("-t", "--template", default="header.txt", help="template macro file")
	parser.add_argument("-b", "--brief", default="brief.json", help="brief file")
	parser.add_argument("-p", "--project", default="cgraph.json", help="project file")
	def func(args):
		project = parse_project(file=args.project)
		brief = parse_brief(file=args.brief)
		template = parse_template(template=args.template, file=args.file, project=project, brief=brief)
		lines = delete_header_from_file(file=args.file)
		lines = add_template_to_file(lines=lines, template=template)
		write_lines_to_file(lines=lines, file=args.file)
	parser.set_defaults(func=func)
	return parser.parse_args()

if __name__ == "__main__":
	args = arg_parse()
	args.func(args)