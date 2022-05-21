PRO = 'cgraph'
VERSION = '0.0.0'
LICENSE = 'GPL-3.0'
project(PRO, 'c', version: VERSION, license: LICENSE)

dir = "."
inc = join_paths(dir, "include")
src = join_paths(dir, "src")
src_type = join_paths(src, "type")
tst = join_paths(dir, "test")
lib = join_paths(dir, "lib")

incdir = include_directories(inc, src_type)
build_root(lib)
source_root(dir)
current_build_dir(lib)
current_source_dir(src)

CC = 'cc' 
CFLAGS = '-std=c89 -Wall -pedantic -fPIC'
CSFLAGS = '-shared'

if get_option('debug').enabled()
CFLAGS += ' -g -DDEBUG'
elif get_option('release').enabled()
CFLAGS += ' -static -O2'
endif

AR = 'ar'
ARFLAGS = '-rcs'

both_libraries(PRO)