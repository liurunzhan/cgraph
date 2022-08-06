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

project "cgraph"
	kind "ConsoleApp"
	language "C"
	includedirs { "include", "src/type" }
	files { "src/**.c" }
