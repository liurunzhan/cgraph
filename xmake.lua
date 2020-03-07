add_includedirs("include")
add_cflags("-ansi –pedantic -pedantic-errors -Wall -fPIC -g")

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
	add_deps("static")
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