@REM Copyright (c) Reverge Studios
@REM ALL RIGHTS RESERVED

@echo off

if "%1"=="" goto :errorNoToolset
if "%2"=="" goto :errorNoProject

call "%~dp0..\..\..\b2.exe" address-model=64 toolset=%1 address-model=64 variant=debug "%~n2" -a -n|"%~dp0vcxproj.exe" "%~2" --cfg debug --bjam_log_stdin --out "%~2" --flt_dir \qvm=qvm* --jamfile_dir "%~dp2" %3 %4 %5 %6 %7 %8 %9
if ERRORLEVEL 1 goto :error
call "%~dp0..\..\..\b2.exe" address-model=64 toolset=%1 address-model=64 variant=release "%~n2" -a -n|"%~dp0vcxproj.exe" "%~2" --cfg release --bjam_log_stdin --out "%~2" --flt_dir \qvm=qvm* --jamfile_dir "%~dp2" %3 %4 %5 %6 %7 %8 %9
if ERRORLEVEL 1 goto :error
exit /B 0

:error
echo.
call "%~dp0..\..\..\tools\build\src\engine\bin.ntx86\b2" address-model=64 toolset=%1 variant=debug %~n3 -a -n>"%~dp0error.bjam.log"
echo Error: "%~dp0vcxproj.exe" %3 --jamfile_dir . --bjam_log_stdin --out %3 --cfg debug %4 %5 %6 %7 %8 %9
exit /B 255

:errorNoToolset
echo.
echo Please specify a bjam toolset as the first parameter, e.g. msvc-14.0.
goto :showUsage

:errorNoProject
echo.
echo Please specify a vcxproj path as the second parameter.
goto :showUsage

:showUsage
echo.
echo Usage:
echo %~nx0 variant vcxproj_path
echo.
exit /B 255
