#!/usr/bin/env -S odin run

package main

import "core:fmt"
import "core:strings"

main :: proc() {
	SEP : string = "/" if ODIN_OS == "windows" else "\\";
	PRO : string = "cgraph";
	DIR : string = ".";
	INC : string = strings.join([]string{PRO, "include"}, SEP);
	SRC : string = strings.join([]string{PRO, "src"}, SEP);
	TST : string = strings.join([]string{PRO, "test"}, SEP);
	LIB : string = strings.join([]string{PRO, "lib"}, SEP);

	
}