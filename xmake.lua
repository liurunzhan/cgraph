target("cgraph")
	set_kind("static")
	add_includedirs("include")
	add_cflags("-ansi –pedantic -pedantic-errors -Wall")
	add_files("src/*.c")
	on_clean(function (target)
		if os.exists(target:targetfile()) then
			os.rm(target:targetfile())
			-- os.rmdir("$(buildir)/$(plat)/$(arch)/$(mode)")
		end
	end)
target_end()

target("cgraph_cl")
	set_kind("binary")
	add_includedirs("include")
	add_cflags("-ansi –pedantic -pedantic-errors -Wall")
	add_files("test/cgraph.c")
	add_deps("cgraph")
	on_run(function (target)
		os.exec("$(buildir)/$(plat)/$(arch)/$(mode)/cgraph_cl $(scriptdir)/test/elements.csv")
	end)
	on_clean(function (target)
		if os.exists("$(buildir)/$(plat)") then 
			os.rmdir("$(buildir)/$(plat)")
		end
	end)
target_end()