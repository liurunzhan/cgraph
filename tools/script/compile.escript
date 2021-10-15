#!/usr/bin/env escript

main([Args]) -> 
	PRO = "cgraph",
	DIR = ".",
	INC = DIR ++ "include",
	SRC = DIR ++ "src",
	TST = DIR ++ "test",
	LIB = DIR ++ "lib",
	io:format(LIB),
	io:format(Args).