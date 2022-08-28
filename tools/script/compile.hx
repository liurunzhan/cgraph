#!/usr/bin/env haxe

class compile {
	static public function main() {
    var PRO = "cgraph"
    var DIR = "."
    var INC = haxe.io.Path.join(DIR, "include")
    var SRC = haxe.io.Path.join(DIR, "src")
    var SRC_TYPE = os.path.join(SRC, "type")
    var TST = haxe.io.Path.join(DIR, "tests")
    var LIB = haxe.io.Path.join(DIR, "lib")
	}
}