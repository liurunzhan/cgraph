#!/usr/bin/python3

import sys
import getopt
import time
import os
import json

def parse_brief(file):
	intro = None
	with open(file, "r") as fin:
		intro = json.loads(fin.read())
	print(intro)

	return intro

def parse_template(template, file, author, email, date, lisence, brief):
	lines = []
	with open(template, "r") as fin:
		for line in fin.readlines():
			line = line.replace("\r", "").replace("\n", "")
			if "@file" in line:
				line = line.replace("${FILE}", file)
			if "@author" in line:
				line = line.replace("${AUTHOR}", author)
			if "@email" in line:
				line = line.replace("${EMAIL}", email)
			if "@date" in line:
				line = line.replace("${DATE}", date)
			if "@lisence" in line:
				line = line.replace("${LISENCE}", lisence)
			if "@brief" in line:
				line = line.replace("${BRIEF}", brief)
			lines.append(line)
	
	return lines

def delete_header_from_file(file):
	lines = []
	flag = False
	cnt = 0
	with open(file, "r") as fin:
		for line in fin.readlines():
			line = line.replace("\r", "").replace("\n", "")
			if "/**" in line and cnt == 0:
				flag = True
				cnt = 1
				continue
			if "*/" in line and cnt == 1:
				flag = False
				cnt = 2
				continue
			if flag == False:
				lines.append(line)
	return lines

def add_template_to_file(lines, template):
	if lines[0].startswith("/**"):
		return template + lines
	else:
		return template + [""] + lines

def write_lines_to_file(lines, file):
	with open(file, "w") as fout:
		for line in lines:
			fout.write(line)

def get_cmd_help(name):
	print("%s [arguments]" % name)
	print("-i --input    : input file")
	print("-o --output   : output file")
	print("-t --template : header template file")
	print("-h --help     : get help")
	sys.exit(0)

if __name__ == "__main__":
	file = None
	author = "liurunzhan"
	email = "liurunzhan@sina.com"
	date = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()) 
	lisence = "GPL-3.0"
	brief = "brief.json"

	name = sys.argv[0]
	argv = sys.argv[1:]
	opts, args = getopt.getopt(argv, "i:o:t:b:h", ["--input=", "--output=", "--template=", "--brief=", "--help"])

	input_file  = None
	output_file = None
	brief_file  = "intro.json"
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
		else:
			get_cmd_help(name)
	
	if input_file is None and (file is None or file == ""):
		print("input file cannot be None")
		sys.exit(-1)
	if output_file is None:
		output_file = input_file + ".tmp"
	brief = parse_brief(brief_file)
	if file not in brief:
		print("%s not in brief file %s" % (file, brief_file))
		sys.exit(-1)
	template = parse_template(template_file, file, author, email, date, lisence, brief[file])
	lines = delete_header_from_file(input_file)
	lines = add_template_to_file(lines, template)
	for line in lines:
		print(line)
	