# cgraph

A C LIBRARY FOR GRAPH ANALYSIS

## Compilation

This library supports mingw32-make, make, cmake and xmake to compile those source files with the version of debug (with the addtional c flags of "-g -DDEBUG") and release (with the addtional c flags of "-static -O2"), cross different platforms of mingw, msys, msys2, cgywin, wsl and linux.

This library also provides shell script [compile.sh](./compile.sh), z shell script [compile.zsh](./compile.zsh) and fish script [compile.fish](./compile.fish) in msys, msys2, cgywin, wsl and linux, batch script [compile.bat](./compile.bat) and powershell script [compile.ps1](./compile.ps1) in mingw to directly compile those source files by C compiler without make tools. All the compile scripts provide the same command-line arguments, without any argument or with the arguments of test, clean, distclean and help.

What's more, this library provides perl script [compile.pl](./compile.pl), perl6 script [compile.p6](./compile.p6), ruby script [compile.rb](./compile.rb), python script [compile.py](./compile.py), lua script [compile.lua](./compile.lua) r script [compile.r](./compile.r) and julia script [compile.jl](./compile.jl) to compile those source files. Makes and shells are good enough to do above things well, but the script languages can do the same as well, especially much easily cross-platform.

In addtion, this library provides some other language scripts, based on jvm, to do the same work, such as java script [compile.java](./compile.java) in openjdk11, scala script [compile.scala](./compile.scala), kotlin script [compile.kts](./compile.kts), clojure script [compile.clj](./compile.clj) and groovy script [compile.groovy](./compile.groovy).

Any compiler who supports STANDARD C89/ANSI C/C99/C11 can compile this library well, such as mingw32-gcc, mingw-w64-i686-gcc, mingw-w64-x86_64-gcc, tcc, gcc and clang. Their flags are lised as bellow. If you want to cross compilers, use flag "-pedantic -Wall -std=c89/c99/c11" or "-pedantic -Wall -ansi" instead.

| tool | optional flags 1 | optional flags 2 |
| :-: | :-: | :-: |
| mingw32-gcc, mingw-w64-i686-gcc, mingw-w64-x86_64-gcc, tcc, gcc | -pedantic -Wall -fpic -std=c89/c99 | -pedantic -pedantic-errors -Wall -fpic -ansi |
| clang |  -pedantic -Wall -std=c89/c99/C11 | -pedantic -Wall -ansi |

## Overview

Do what you want to do, and be what you want to be!

I am used to using process-oriented programming thinking and languages to solve problems, like C, but now I want to use pointer and structural variables in C to realize some features in object-oriented programming, and macro in C to realize the features in generic programming and interface-oriented programming.

