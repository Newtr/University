@echo off
cls
cls

for %%A in ("%~dpnx0") do (
  set "FilePath=%%~fA"
  set "FileName=%%~nA"
)

for /f "tokens=1-2" %%B in ('dir /tc "%FilePath%" ^| find "%FileName%"') do (
  set "FileCreateDateDate=%%B"
  set "FileCreateTime=%%C"
)

echo --File name:     %FileName%
echo --File created date:  %FileCreateDateDate% %FileCreateTime%
echo --File path:     %FilePath%
pause