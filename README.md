# cgraph
________
A C library for graph and mathematical analysis

* [Compilation](#compilation)
  * [Standard way](#standard-way)
  * [Custom way](#custom-way)
  * [Compiler](#compiler)
  * [Summary](#summary)
    * [Platform List](#platform-list)
    * [Compiler List](#compiler-list)
    * [Script List](#script-list)
* [Overview](#overview)
* [Structure](#structure)
* [Extension](#extension)
  * [Dist](#dist)
  * [Julia](#julia)
  * [Perl](#perl)
  * [Python](#python)
  * [R](#r)

## Compilation
______________
Learn more types of programming languages, and know more ways to ponder, model and deal with real problems.

### Standard way
________________
This library can be configured by ***autotools*** with [autogen.sh](./autogen.sh) and ***configure***, compiled by Makefiles with the following standard steps:
```bash
  ./autogen.sh  
  ./configure --prefix=$(prefix) --enable-gtk-doc
  make  
```
and cleaned by Makefiles with the following standard steps:  
```bash
  make clean  
  make distclean
```

Only the platform supports bash and autotools that can use the standard way to compile this library, such as Linux. If the users use Windows OS, use msys, msys2, cygwin or wsl (in Windows 10) instead. Users in other Unix-like OS can use the standard way well.

### Custom way
______________
This library supports ***mingw32-make*** ([compile.mk](./script/compile.mk)), ***make*** ([compile.mk](./script/compile.mk)), ***cmake*** ([CMakeLists.txt](./script/CMakeLists.txt)), ***xmake*** ([xmake.lua](./script/xmake.lua)), ***meson*** ([meson.build](./script/meson.build)) and ***ninja*** ([compile.ninja](./script/compile.ninja)) to compile all the source files with the version of debug (with the addtional compilation flags of "-g -DDEBUG") and release (with the addtional compilation flags of "-static -O2"), cross different platforms of ***mingw***, ***msys***, ***msys2***, ***cygwin***, ***wsl*** and ***linux***.

This library also provides ***bash shell script*** [compile.sh](./script/compile.sh), ***z shell script*** [compile.zsh](./script/compile.zsh), ***fish shell script*** [compile.fish](./script/compile.fish), ***c shell script*** [compile.csh](./script/compile.csh) and ***v shell script*** [compile.vsh](./script/compile.vsh) in ***msys***, ***msys2***, ***cygwin***, ***wsl*** and ***linux***, ***batch script*** [compile.bat](./script/compile.bat) and ***powershell script*** [compile.ps1](./script/compile.ps1) in ***mingw*** to directly compile this library by C compiler without make tools in special platforms(notice that incremental compilation is unsupported). All the compile scripts provide the same command-line arguments, without any argument or with the arguments of ***test***, ***clean***, ***distclean*** and ***help***.

What's more, this library provides ***perl script*** [compile.pl](./script/compile.pl), ***perl6/raku*** script [compile.raku](./script/compile.raku), ***ruby script*** [compile.rb](./script/compile.rb), ***python script*** [compile.py](./script/compile.py), ***lua script*** [compile.lua](./script/compile.lua), ***r script*** [compile.r](./script/compile.r), ***julia script*** [compile.jl](./script/compile.jl), ***tcl script*** [compile.tcl](./script/compile.tcl), ***ocaml script*** [compile.ml](./script/compile.ml), ***lisp script*** [compile.lisp](./script/compile.lisp) in ***clisp***, ***elixir script*** [compile.exs](./script/compile.exs) and ***io script*** [compile.io](./script/compile.io) to compile this library(where incremental compilation is also unsupported here). Make tools and shells are good enough to do above things well, but the script languages can do the same as well, especially much easily cross-platform.

In addtion, this library provides some other language scripts, based on jvm, to do the same work, such as ***java script*** [compile.java](./script/compile.java) in ***openjdk11***, ***scala script*** [compile.scala](./script/compile.scala), ***kotlin script*** [compile.kts](./script/compile.kts), ***clojure script*** [compile.clj](./script/compile.clj) and ***groovy script*** [compile.groovy](./script/compile.groovy).

Some compiled languages realized by given compilers with special extension tools can also be used to write scripts, such as ***c script*** [compile.c](./script/compile.c) in ***tcc***, ***go script*** [compile.go](./script/compile.go) in ***go*** with ***gorun***, ***swift script*** [compile.swift](./script/compile.swift), ***haskell script*** [compile.hs](./script/compile.hs) in ***haskell*** with ***runhaskell***, ***rust script*** [compile.rs](./script/compile.rs) in ***rust*** with ***rustx***, ***erlang script*** [compile.escript](./script/compile.escript), ***nims script*** [compile.nims](./script/compile.nims) and ***zig script*** [compile.zig](./script/compile.zig).

All above ways are called with [Makefile.mk](./Makefile.mk) in MSYS, MSYS2, CYGWIN or Linux platform by
```bash
make -f Makefile.mk $(TOOL) CMD=$(CMD)  
```
or in Windows platform by
```cmd
mingw32-make.exe -f Makefile.mk $(TOOL) CMD=$(CMD)  
```

### Compiler
____________
Any compiler who supports **STANDARD C89/ANSI C/C99/C11** can compile this library well, such as ***mingw32-gcc***, ***mingw-w64-i686-gcc***, ***mingw-w64-x86_64-gcc***, ***tcc***, ***gcc*** and ***clang***. Their flags are lised as bellow. If you want to cross compilers, use flag "-pedantic -Wall -std=c89/c99/c11" or "-pedantic -Wall -ansi" instead.

| tool name | optional flags 1 | optional flags 2 |
| :-: | :-: | :-: |
| ***mingw32-gcc***, ***mingw-w64-i686-gcc***, ***mingw-w64-x86_64-gcc***, ***tcc***, ***gcc*** | -pedantic -Wall -fPIC -std=**c89/c99/c11** | -pedantic -pedantic-errors -Wall -fPIC -ansi |
| ***clang*** |  -pedantic -Wall -std=**c89/c99/c11** | -pedantic -Wall -ansi |

### Summary
___________
#### Platform List
__________________
* [mingw](http://www.mingw.org)
* [msys](http://www.mingw.org)
* [msys2](https://www.msys2.org)
* [cygwin](https://cygwin.com)
* [wsl](https://docs.microsoft.com/en-us/windows/wsl/)
* [linux](https://www.linux.org)

#### Compiler List
__________________
* [mingw32-gcc](http://www.mingw.org)
* [mingw-w64-i686-gcc](http://www.mingw-w64.org)
* [mingw-w64-x86_64-gcc](http://www.mingw-w64.org) or [MinGW Distro * nuwen.net](https://nuwen.net/mingw.html)
* [tcc](https://bellard.org/tcc/)
* [gcc](http://gcc.gnu.org)
* [clang](https://clang.llvm.org)

#### Script List
________________
All the involved compilation scripts in this library are listed as below. User can use [Configure.pl](./Configure.pl) to change their default configuration (ongoing...).

* ***CMake*** [CMakeLists.txt](./script/CMakeLists.txt)
* ***DOS Batch*** [compile.bat](./script/compile.bat)
* ***C*** [compile.c](./script/compile.c)
* ***Clojure*** [compile.clj](./script/compile.clj)
* ***C Shell*** [compile.csh](./script/compile.csh)
* ***Erlang*** [compile.escript](./script/compile.escript)
* ***Elixir*** [compile.exs](./script/compile.exs)
* ***Fish Shell*** [compile.fish](./script/compile.fish)
* ***Go*** [compile.go](./script/compile.go)
* ***Groovy*** [compile.groovy](./script/compile.groovy)
* ***Haskell*** [compile.hs](./script/compile.hs)
* ***IO*** [compile.io](./script/compile.io)
* ***Java*** [compile.java](./script/compile.java)
* ***Julia*** [compile.jl](./script/compile.jl)
* ***Kotlin*** [compile.kts](./script/compile.kts)
* ***Lisp*** [compile.lisp](./script/compile.lisp)
* ***Lua*** [compile.lua](./script/compile.lua)
* ***make*** [compile.mk](./script/compile.mk)
* ***Ocaml*** [compile.ml](./script/compile.ml)
* ***Nim*** [compile.nims](./script/compile.nims)
* ***Ninja*** [compile.ninja](./script/compile.ninja)
* ***Perl*** [compile.pl](./script/compile.pl)
* ***Perl6/Raku*** [compile.raku](./script/compile.raku)
* ***Powershell*** [compile.ps1](./script/compile.ps1)
* ***Python*** [compile.py](./script/compile.py)
* ***R*** [compile.r](./script/compile.r)
* ***Ruby*** [compile.rb](./script/compile.rb)
* ***Rust*** [compile.rs](./script/compile.rs)
* ***Scala*** [compile.scala](./script/compile.scala)
* ***Bourne Shell*** [compile.sh](./script/compile.sh)
* ***Swift*** [compile.swift](./script/compile.swift)
* ***Tcl/Tk*** [compile.tcl](./script/compile.tcl)
* ***Typescript*** [compile.ts](./script/compile.ts)
* ***V Shell*** [compile.vsh](./script/compile.vsh)
* ***Zig*** [compile.zig](./script/compile.zig)
* ***Z Shell*** [compile.zsh](./script/compile.zsh)
* ***Meson*** [meson.build](./script/meson.build)
* ***XMake*** [xmake.lua](./script/compile.lua)

## Overview
___________
Do what you want to do, and be what you want to be!

I am used to using process-oriented programming thinking and languages to solve problems, like C and Perl, but now I want to use pointer and structural variables in C to realize some features in object-oriented programming, and macro in C to realize the features in generic programming and interface-oriented programming.

A lot of repetitive work used to be done by compilers, must be done by hand while programming with C. The process may be tough and boring, but the target is cool and interesting enough! And it is also meaningful for me to understand the mechanism behind object-oriented compilers. Writing a library by hand will be better than packaging the APIs of a known library, for the case that its stability can be guaranteed. 

## Structure
____________


## Extension
____________

### Dist
________

### Julia
_________

### Perl
________

### Python
__________

### R
_____


