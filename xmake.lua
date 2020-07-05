add_includedirs("include")
add_cflags("-pedantic", "-Wall", "-fpic", "-std=c89", {force = true})

if is_mode("debug") then
	-- add_defines("DEBUG")
	-- set_symbols("debug")
	-- set_optimize("none")
	add_cflags("-g", "-DDEBUG", {force = true})
end

if is_mode("release") then
	print("release mode")
	-- set_symbols("hidden")
	-- set_strip("all")
	-- set_symbols("debug")
	add_cflags("-static", "-O2", {force = true})
end

-- if is_mode("profile") then
-- 	set_symbols("debug")
-- end

target("static")
	set_kind("static")
	set_basename("cgraph")
	add_files("src/*.c")
	on_clean(function (target)
		if os.exists(target:targetfile()) then
			os.rm(target:targetfile())
		end
	end)
target_end()

target("shared")
	set_kind("shared")
	set_basename("cgraph")
	add_files("src/*.c")
	on_clean(function (target)
		if os.exists(target:targetfile()) then
			os.rm(target:targetfile())
		end
	end)
target_end()

target("cgraph")
	set_kind("binary")
	set_basename("cgraph")
	add_files("test/cgraph.c")
	add_deps("shared")
	on_run(function (target)
		os.exec("%s $(scriptdir)/test/elements.csv", target:targetfile())
	end)
	on_clean(function (target)
		if os.exists(target:targetfile()) then
			os.rm(target:targetfile())
			-- os.rmdir("$(buildir)/$(plat)/$(arch)/$(mode)")
		end
	end)
target_end()