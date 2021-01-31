[toc]

# cgraph

A C library for graph and mathematical analysis

## Compilation
### Standard way
This library can be configured by autotools with [autogen.sh](./autogen.sh) and configure, compiled by Makefiles with following standard steps:
  ./autogen.sh
  ./configure --prefix=$(prefix) --enable-static/--enable-dynamic
  make
and cleaned by Makefiles with following standard steps:
  make clean
  make distclean

Only the platform supports bash and autotools that can use the standard way to compile this library. If the users use Windows OS, use msys, msys2 or cygwin instead. Other unix-like OS can use the standard way well.

### Custom way
This library supports mingw32-make, make, cmake and xmake to compile all the source files with the version of debug (with the addtional compilation flags of "-g -DDEBUG") and release (with the addtional compilation flags of "-static -O2"), cross different platforms of mingw, msys, msys2, cgywin, wsl and linux.

This library also provides shell script [compile.sh](./script/compile.sh), z shell script [compile.zsh](./script/compile.zsh) and fish script [compile.fish](./script/compile.fish) in msys, msys2, cgywin, wsl and linux, batch script [compile.bat](./script/compile.bat) and powershell script [compile.ps1](./script/compile.ps1) in mingw to directly compile this library by C compiler without make tools in special platforms(notice that incremental compilation is unsupported). All the compile scripts provide the same command-line arguments, without any argument or with the arguments of test, clean, distclean and help.

What's more, this library provides perl script [compile.pl](./script/compile.pl), perl6 script [compile.p6](./script/compile.p6), ruby script [compile.rb](./script/compile.rb), python script [compile.py](./script/compile.py), lua script [compile.lua](./script/compile.lua) r script [compile.r](./script/compile.r) and julia script [compile.jl](./script/compile.jl) to compile this library(where incremental compilation is also unsupported here). Makes and shells are good enough to do above things well, but the script languages can do the same as well, especially much easily cross-platform.

In addtion, this library provides some other language scripts, based on jvm, to do the same work, such as java script [compile.java](./script/compile.java) in openjdk11, scala script [compile.scala](./script/compile.scala), kotlin script [compile.kts](./script/compile.kts), clojure script [compile.clj](./script/compile.clj) and groovy script [compile.groovy](./script/compile.groovy).

### Compiler
Any compiler who supports STANDARD C89/ANSI C/C99/C11 can compile this library well, such as mingw32-gcc, mingw-w64-i686-gcc, mingw-w64-x86_64-gcc, tcc, gcc and clang. Their flags are lised as bellow. If you want to cross compilers, use flag "-pedantic -Wall -std=c89/c99/c11" or "-pedantic -Wall -ansi" instead.

| tool name | optional flags 1 | optional flags 2 |
| :-: | :-: | :-: |
| mingw32-gcc, mingw-w64-i686-gcc, mingw-w64-x86_64-gcc, tcc, gcc | -pedantic -Wall -fPIC -std=c89/c99/c11 | -pedantic -pedantic-errors -Wall -fPIC -ansi |
| clang |  -pedantic -Wall -std=c89/c99/c11 | -pedantic -Wall -ansi |

## Overview

Do what you want to do, and be what you want to be!

I am used to using process-oriented programming thinking and languages to solve problems, like C and Perl, but now I want to use pointer and structural variables in C to realize some features in object-oriented programming, and macro in C to realize the features in generic programming and interface-oriented programming.

A lot of repetitive work used to be done by compilers, but now must be done by hand. The programming process may be tough and boring, but the target is cool and interesting enough! And it is also meaningful for me to understand the mechanism behind object-oriented compilers.

## Structure

