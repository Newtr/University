chcp 65001
@echo off
cls


echo -- params: %*
echo -- mode: %1
echo -- file name: %2

if "%1" equ "" (
    echo ---+  %~n0 mode file
    echo ---++  mode = {create, delete}
    echo ---++  file  = name
) else (
    if "%1" equ "delete" (
        if "%2" equ "" (
            echo ---+ no name
        ) else (
            if not exist "%2" (
                echo ---+ file %2 not found
            ) else (
                del "%2"
                echo ---+ file %2 deleted
            )
        )
    ) else if "%1" equ "create" (
        if "%2" equ "" (
            echo ---+ no name
        ) else (
            if exist "%2" (
                echo ---+ file %2 exist
            ) else (
                copy NUL %2 >NUL
                echo ---+ file %2 created
            )
        )
    ) else (
        echo ---+ no mode was choosed
    )
)

pause