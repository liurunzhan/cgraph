#!/usr/bin/env python3

import sys
import getopt
import time
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
	lines = []
	with open(template, "r") as fin:
		for line in fin.readlines():
			line = line.replace("\r", "").replace("\n", "")
			if "@file" in line:
				line = line.replace("${FILE}", file if not file.endswith(".in") else file.rstrip(".in"))
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
				line = line.replace("${BRIEF}", brief[file])
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
	if lines[0].startswith("/**"):
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

def get_cmd_help(name):
	print("%s [arguments]" % name)
	print("-i --input    : input file")
	print("-o --output   : output file")
	print("-t --template : header template file")
	print("-h --help     : get help")
	sys.exit(0)

if __name__ == "__main__":
	name = sys.argv[0]
	argv = sys.argv[1:]
	opts, args = getopt.getopt(argv, "i:o:t:b:p:h", ["--input=", "--output=", "--template=", "--brief=", "--project=" "--help"])

	file          = None
	input_file    = None
	output_file   = None
	project_file  = "cgraph.json"
	brief_file    = "brief.json"
	template_file = "header.txt"
	for opt, arg in opts:
		if opt in ["-i", "--input"]:
			input_file = arg
			file = os.path.basename(input_file)
		elif opt in ["-o", "--output"]:
			output_file = arg
		elif opt in ["-t", "--template"]:
			template_file = arg
		elif opt in ["-b", "--brief"]:
			brief_file = arg
		elif opt in ["-p", "--project"]:
			project_file = arg
		else:
			get_cmd_help(name)
	
	if input_file is None and (file is None or file == ""):
		print("input file cannot be None")
		sys.exit(-1)
	if output_file is None:
		output_file = input_file
	
	project = parse_project(project_file)
	brief = parse_brief(brief_file)
	if file not in brief:
		print("%s not in brief file %s" % (file, brief_file))
		sys.exit(-1)
	
	template = parse_template(template_file, file, project, brief)
	lines = delete_header_from_file(input_file)
	lines = add_template_to_file(lines, template)
	write_lines_to_file(lines, output_file)
	