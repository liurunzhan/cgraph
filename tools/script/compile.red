#!/usr/bin/red

string: make string! PRO "cgraph"
string: make string! DIR "."
string: make string! INC File.join(DIR, "include")
string: make string! SRC File.join(DIR, "src")
string: make string! SRC_TYPE File.join(SRC, "type")
string: make string! TST File.join(DIR, "tests")
string: make string! LIB File.join(DIR, "lib")
