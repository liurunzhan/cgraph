#!/usr/bin/env python3

import argparse
import time
import sys
import os
import json

project_default_property = {
	"package" : "cgraph",
	"author" : "liurunzhan",
	"email" : "liurunzhan@sina.com",
	"date" : time.strftime("%Y-%m-%d", time.localtime()),
	"lisence" : "GPL-3.0",
	"version" : "0.0.0",
	"url" : "https://github.com/liurunzhan/cgraph"
}

def parse_project(file):
	project = None
	with open(file, "r") as fin:
		project = json.loads(fin.read())
	for property in project_default_property:
		if property not in project or project[property] == "":
			project[property] = project_default_property[property]
	
	return project

def parse_brief(file):
	intro = None
	with open(file, "r") as fin:
		intro = json.loads(fin.read())

	return intro

def parse_template(template, file, project, brief, brief_file):
	basename = os.path.basename(file)
	if basename not in brief:
		print("%s not in brief file %s" % (basename, brief_file))
		sys.exit(0)
	lines = []
	template_property = {
		"@file"    : ["${FILE}",  basename.rstrip(".in")],
		"@brief"   : ["${BRIEF}", brief[basename]],
	}
	for property in project:
		used_property = "@" + property
		if used_property not in template_property:
			template_property[used_property] = ["${%s}" % property.upper(), project[property]]
	with open(template, "r") as fin:
		for line in fin.readlines():
			line = line.rstrip()
			for property in template_property:
				if property in line:
					values = template_property[property]
					line = line.replace(values[0], values[1])
					break
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
	parser = argparse.ArgumentParser(description="update C-type macro definitions", formatter_class=argparse.ArgumentDefaultsHelpFormatter)
	parser.add_argument("files", nargs="+", type=str, help="parsed source file")
	parser.add_argument("-t", "--template", default="header.txt", help="template macro file")
	parser.add_argument("-b", "--brief", default="brief.json", help="brief file")
	parser.add_argument("-p", "--project", default="cgraph.json", help="project file")
	def func(args):
		project = parse_project(args.project)
		brief = parse_brief(args.brief)
		for file in args.files:
			template = parse_template(template=args.template, file=file, project=project, brief=brief, brief_file=args.brief)
			lines = delete_header_from_file(file=file)
			lines = add_template_to_file(lines=lines, template=template)
			write_lines_to_file(lines=lines, file=file)
	parser.set_defaults(func=func)
	return parser.parse_args()

if __name__ == "__main__":
	args = arg_parse()
	args.func(args)