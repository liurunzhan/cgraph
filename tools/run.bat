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
	python %TOOL%\header.py %%F -t %TOOL%\header.txt -b %TOOL%\brief.json -p %TOOL%\cgraph.json
)

@echo update source template in %INC%\cgraph_template_off.h
python %TOOL%\macro.py %INC%\cgraph_template_off.h -t %TOOL%\template_off.macro -c "end of cgraph_template_off"

@echo update source template in %INC%\cgraph_template_check.h
python %TOOL%\macro.py %INC%\cgraph_template_check.h -t %TOOL%\template_check.macro -c "end of cgraph_template_check"
