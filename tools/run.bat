@echo off

set DIR=.
set TOOL=%DIR%\tools
set INC=%DIR%\include

if not exist %TOOL% (
  @echo %TOOL% does not exist
	exit
)

if not exist %INC% (
  @echo %INC% does not exist
	exit
)

for %%F in (%INC%\*) do (
	@echo add header template to %%F
	python3 %TOOL%\header.py %%F -t %TOOL%\header.macro -b %TOOL%\brief.json -p %TOOL%\cgraph.json
	if 0 != %errorlevel% (
		exit
	)
)

@echo update source template in %INC%\cgraph_template_off.h.in
python3 %TOOL%\macro.py %INC%\cgraph_template_off.h.in -o %INC%\cgraph_template_off.h -t %TOOL%\template_off.macro -c "end of cgraph_template_off"

@echo update source template in %INC%\cgraph_template_check.h
python3 %TOOL%\macro.py %INC%\cgraph_template_check.h.in -o %INC%\cgraph_template_check.h -t %TOOL%\template_check.macro -c "end of cgraph_template_check"
