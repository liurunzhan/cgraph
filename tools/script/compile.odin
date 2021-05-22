#!/usr/bin/env -S odin run

package main

import "core:fmt"
import "core:unicode/utf8"

main :: proc() {
	PRO : string = "cgraph";
	DIR : string = ".";
	// INC : string = path:filepath.join(DIR, "include");
	// SRC : string = path.join(DIR, "src");
	// TST : string = path.join(DIR, "test");
	// LIB : string = path.join(DIR, "lib");

	fmt.println("hello world!");
}