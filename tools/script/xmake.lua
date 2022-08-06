set_project("cgraph")
set_version("0.0.0")

add_includedirs("include", "src/type")
add_files("src/**.c")
add_cflags("-std=c89", "-Wall", "-pedantic", "-fPIC",  {force = true})

if is_mode("debug") then
	set_symbols("debug")
	set_optimize("none")
	add_cflags("-g", "-DDEBUG", {force = true})
end

if is_mode("release") then
	set_symbols("hidden")
	set_strip("all")
	add_cflags("-static", "-O2", {force = true})
end

-- if is_mode("profile") then
-- 	set_symbols("debug")
-- end

if is_plat("linux", "macosx") then
	add_links("m")
end

target("static")
	set_kind("static")
	set_basename("cgraph")
	on_clean(function (target)
		if os.exists(target:targetfile()) then
			os.rm(target:targetfile())
		end
	end)
target_end()

target("shared")
	set_kind("shared")
	set_basename("cgraph")
	on_clean(function (target)
		if os.exists(target:targetfile()) then
			os.rm(target:targetfile())
		end
	end)
target_end()

target("cgraph")
	set_kind("binary")
	set_basename("cgraph")
	add_files("tests/cgraph.c")
	add_deps("shared")
	on_run(function (target)
		os.exec("%s $(scriptdir)/tests/elements.csv", target:targetfile())
	end)
	on_clean(function (target)
		if os.exists(target:targetfile()) then
			os.rm(target:targetfile())
			-- os.rmdir("$(buildir)/$(plat)/$(arch)/$(mode)")
		end
	end)
target_end()
