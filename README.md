# cgraph
________

A C library for graph and mathematical analysis

```shell
                                                _                               
                                               | |                              
                       ___ __ _ _ __ __ _ _ __ | |__                            
                      / __/ _` | '__/ _` | '_ \| '_ \                           
                     | (_| (_| | | | (_| | |_) | | | |                          
                      \___\__, |_|  \__,_| .__/|_| |_|                          
                           __/ |         | |                                    
                          |___/          |_|                                    
```

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
This library can be configured by ***autotools*** with [autogen.sh](./autogen.sh) and ***configure***, compiled and checked by Makefiles with the following standard steps:
```bash
  chmod +x ./autogen.sh
  ./autogen.sh
  ./configure --prefix=${prefix} --enable-gtk-doc
  make
  make doc
  make check
```
packaged and checked by Makefiles with the following standard steps: 
```bash
  make dist  
  make distcheck
```
and cleaned by Makefiles with the following standard steps:  
```bash
  make clean  
```
or
```bash
  make distclean  
```
and updated by Makefiles and git with the following standard steps:
```bash
  make update
```

Only the platform supports bash and autotools that can use the standard way to compile this library, such as Linux and other Unix-like OS. If the users use Windows OS, use msys, msys2, cygwin or wsl instead.

### Custom way
______________
This library supports ***mingw32-make*** ([compile.mk](./tools/script/compile.mk)), ***make*** ([compile.mk](./tools/script/compile.mk)), ***cmake*** ([CMakeLists.txt](./tools/script/CMakeLists.txt)), ***xmake*** ([xmake.lua](./tools/script/xmake.lua)), ***meson*** ([meson.build](./tools/script/meson.build)) and ***ninja*** ([compile.ninja](./tools/script/compile.ninja)) to compile all the source files with the version of debug (with the addtional compilation flags of "-g -DDEBUG") and release (with the addtional compilation flags of "-static -O2"), cross different platforms of ***mingw***, ***msys***, ***msys2***, ***cygwin***, ***wsl*** and ***linux***.

This library also provides ***bash shell script*** [compile.sh](./tools/script/compile.sh), ***z shell script*** [compile.zsh](./tools/script/compile.zsh), ***fish shell script*** [compile.fish](./tools/script/compile.fish), ***c shell script*** [compile.csh](./tools/script/compile.csh) and ***v shell script*** [compile.vsh](./tools/script/compile.vsh) in ***msys***, ***msys2***, ***cygwin***, ***wsl*** and ***linux***, ***batch script*** [compile.bat](./tools/script/compile.bat) and ***powershell script*** [compile.ps1](./tools/script/compile.ps1) in ***mingw*** to directly compile this library by C compiler without make tools in special platforms(notice that incremental compilation is unsupported). All the compile scripts provide the same command-line arguments, without any argument or with the arguments of ***test***, ***clean***, ***distclean*** and ***help***.

What's more, this library provides ***perl script*** [compile.pl](./tools/script/compile.pl), ***perl6/raku*** script [compile.raku](./tools/script/compile.raku), ***ruby script*** [compile.rb](./tools/script/compile.rb), ***crystal script*** [compile.cr](./tools/script/compile.cr), ***python script*** [compile.py](./tools/script/compile.py), ***lua script*** [compile.lua](./tools/script/compile.lua), ***r script*** [compile.r](./tools/script/compile.r), ***julia script*** [compile.jl](./tools/script/compile.jl), ***tcl script*** [compile.tcl](./tools/script/compile.tcl), ***ocaml script*** [compile.ml](./tools/script/compile.ml), ***lisp script*** [compile.lisp](./tools/script/compile.lisp) in ***clisp***, ***elixir script*** [compile.exs](./tools/script/compile.exs) and ***io script*** [compile.io](./tools/script/compile.io) to compile this library(where incremental compilation is also unsupported here). Make tools and shells are good enough to do above things well, but the script languages can do the same as well, especially much easily cross-platform.

In addtion, this library provides some other language scripts, based on jvm, to do the same work, such as ***java script*** [compile.java](./tools/script/compile.java) in ***openjdk11***, ***scala script*** [compile.scala](./tools/script/compile.scala), ***kotlin script*** [compile.kts](./tools/script/compile.kts), ***clojure script*** [compile.clj](./tools/script/compile.clj) and ***groovy script*** [compile.groovy](./tools/script/compile.groovy).

Some compiled languages realized by given compilers with special extension tools can also be used to write scripts, such as ***c script*** [compile.c](./tools/script/compile.c) in ***tcc***, ***go script*** [compile.go](./tools/script/compile.go) in ***go*** with ***gorun***, ***swift script*** [compile.swift](./tools/script/compile.swift), ***haskell script*** [compile.hs](./tools/script/compile.hs) in ***haskell*** with ***runhaskell***, ***rust script*** [compile.rs](./tools/script/compile.rs) in ***rust*** with ***rustx***, ***erlang script*** [compile.escript](./tools/script/compile.escript), ***nims script*** [compile.nims](./tools/script/compile.nims) and ***zig script*** [compile.zig](./tools/script/compile.zig).

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
* [archwsl](https://github.com/yuk7/ArchWSL)
* [linux](https://www.linux.org)

#### Compiler List
__________________
* [mingw32-gcc](http://www.mingw.org)
* [mingw-w64-i686-gcc/mingw-w64-x86_64-gcc](http://www.mingw-w64.org)
* [MinGW Distro - nuwen.net](https://nuwen.net/mingw.html)
* [tcc](https://bellard.org/tcc/)
* [gcc](http://gcc.gnu.org)
* [clang](https://clang.llvm.org)

#### Script List
________________
All the involved compilation scripts in this library are listed as below. User can use [Configure.pl](./Configure.pl) to change their default configuration (ongoing...).

* ***CMake*** [CMakeLists.txt](./tools/script/CMakeLists.txt)
* ***DOS Batch*** [compile.bat](./tools/script/compile.bat)
* ***C*** [compile.c](./tools/script/compile.c)
* ***Ceylon*** [compile.ceylon](./tools/script/compile.ceylon)
* ***Clojure*** [compile.clj](./tools/script/compile.clj)
* ***Crystal*** [compile.cr](./tools/script/compile.cr)
* ***C Shell*** [compile.csh](./tools/script/compile.csh)
* ***D*** [compile.d](./tools/script/compile.d)
* ***Erlang*** [compile.escript](./tools/script/compile.escript)
* ***Elixir*** [compile.exs](./tools/script/compile.exs)
* ***Fish Shell*** [compile.fish](./tools/script/compile.fish)
* ***Go*** [compile.go](./tools/script/compile.go)
* ***Groovy*** [compile.groovy](./tools/script/compile.groovy)
* ***Haskell*** [compile.hs](./tools/script/compile.hs)
* ***IO*** [compile.io](./tools/script/compile.io)
* ***Java*** [compile.java](./tools/script/compile.java)
* ***Julia*** [compile.jl](./tools/script/compile.jl)
* ***K Shell*** [compile.ksh](./tools/script/compile.ksh)
* ***Kotlin*** [compile.kts](./tools/script/compile.kts)
* ***Lisp*** [compile.lisp](./tools/script/compile.lisp)
* ***Lua*** [compile.lua](./tools/script/compile.lua)
* ***Make*** [compile.mk](./tools/script/compile.mk)
* ***Ocaml*** [compile.ml](./tools/script/compile.ml)
* ***Nims*** [compile.nims](./tools/script/compile.nims)
* ***Ninja*** [compile.ninja](./tools/script/compile.ninja)
* ***Odin*** [compile.odin](./tools/script/compile.odin)
* ***Perl*** [compile.pl](./tools/script/compile.pl)
* ***Powershell*** [compile.ps1](./tools/script/compile.ps1)
* ***Python*** [compile.py](./tools/script/compile.py)
* ***R*** [compile.r](./tools/script/compile.r)
* ***Raku*** [compile.raku](./tools/script/compile.raku)
* ***Ruby*** [compile.rb](./tools/script/compile.rb)
* ***Rebol*** [compile.rebol](./tools/script/compile.rebol)
* ***Red*** [compile.red](./tools/script/compile.red)
* ***Rust*** [compile.rs](./tools/script/compile.rs)
* ***Scala*** [compile.scala](./tools/script/compile.scala)
* ***Bourne Shell*** [compile.sh](./tools/script/compile.sh)
* ***Swift*** [compile.swift](./tools/script/compile.swift)
* ***Tcl/Tk*** [compile.tcl](./tools/script/compile.tcl)
* ***Typescript*** [compile.ts](./tools/script/compile.ts)
* ***V Shell*** [compile.vsh](./tools/script/compile.vsh)
* ***Zig*** [compile.zig](./tools/script/compile.zig)
* ***Z Shell*** [compile.zsh](./tools/script/compile.zsh)
* ***Meson*** [meson.build](./tools/script/meson.build)
* ***Premake*** [premake.lua](./tools/script/premake.lua)
* ***XMake*** [xmake.lua](./tools/script/xmake.lua)

## Overview
___________
Do what you want to do, and be what you want to be!

I used to use process-oriented programming thinking and languages to solve problems, like C and Perl, but now I want to use pointer and structural variables in C to realize some features in object-oriented programming, and macro in C to realize the features in generic programming and interface-oriented programming.

A lot of repetitive work used to be done by object-oriented compilers, must be done by hand while programming with C. The process may be tough and boring, but the target is cool and interesting enough! And it is also meaningful for me to understand the mechanism behind object-oriented compilers. Writing a library by hand will be better than packaging the APIs of a known library, for the case that its stability and safety can be guaranteed. 

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


