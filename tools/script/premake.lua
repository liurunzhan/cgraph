-- premake.lua

workspace "cgraph"
	configurations { "Debug", "Release" }

	filter "configurations:Debug"
		buildoptions { "-g", "-DDEBUG" }
		targetdir { "build/debug" }

	filter "configurations:Release"
		buildoptions { "-static", "-O2" }
		optimize "On"
		targetdir { "build/release" }

platforms { }

project "cgraph"
	kind "ConsoleApp"
	language "C"
	includedirs { "include" }
	files { "src/func/*.c", "src/type/basic/*.c", "src/type/data/*.c", "src/type/object/*.c", "src/type/structure/*.c", "src/type/*.c", "src/graph/*.c", "src/game/*.c" }