chcp 65001
echo off
cls

echo --parameter 1: %1
echo --paramete 2: %2
echo --paramete 3: %3
set /A res = %1 %3 %2
echo %res%
pause