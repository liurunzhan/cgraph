#!/usr/bin/env python3

import argparse
import os
import string

help_template = string.Template("""do compile, test, clean, distclean or help operations to ${project} with ${cmd}
""")

def add_subparsers(subparsers, project, cmd, help):
	subparser = subparsers.add_parser(cmd, help=help)
	subparser.add_argument("action", choices=["compile", "test", "clean", "distclean", "help"], help=help_template.substitute(project=project, cmd=cmd))
	def func(args):
		cmd = None
		if args.action == "compile":
			cmd = ""
		elif args.action == "test":
			cmd = ""
		elif args.action == "clean":
			cmd = ""
		elif args.action == "distclean":
			cmd = ""
		else:
			cmd = ""
		if cmd:
			os.system(cmd)
	subparser.set_defaults(func=func)

	return subparser

def cmd_arg_parse(project):
	parser = argparse.ArgumentParser(description="test compile script")
	subparsers = parser.add_subparsers()
	tools = ["make", "cmake", "xmake"]
	for tool in tools:
		add_subparsers(subparsers, project, tool, "%s script" % (tool))

	return parser.parse_args()
	
if __name__ == "__main__":
	project = "cgraph"
	args = cmd_arg_parse(project=project)
	args.func(args)