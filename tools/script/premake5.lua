workspace "cgraph"
startproject "cgraph"

configurations { "Debug", "Release" }

configuration "Debug"
flags { "-g", "-DDEBUG" }

configuration "Release"
flags { "-static", "-O2" }

platforms { }

project "cgraph"
kind "ConsoleApp"
language "C"
files { "./src/*.c" }