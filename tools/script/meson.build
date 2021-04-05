PRO = 'cgraph'
VERSION = '0.0.0'
LICENSE = 'GPL-3.0'
project(PRO, 'c', version: VERSION, license: LICENSE)
library(PRO)

incdir = include_directories('include')

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