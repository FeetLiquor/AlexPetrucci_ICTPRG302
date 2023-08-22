@echo off

rem  setting variables
set build_dir=%~dp0out\build\x64-Debug\
set sfml_build_dir=%build_dir%libs\SFML-2.6.0\lib\
set assets_dir=%~dp0assets\

rem  moving dlls
move %sfml_build_dir%sfml-graphics-d-2.dll %build_dir%
move %sfml_build_dir%sfml-window-d-2.dll %build_dir%
move %sfml_build_dir%sfml-system-d-2.dll %build_dir%

rem  copying assets
xcopy /s /y %assets_dir%fonts\*.* %build_dir%
xcopy /s /y %assets_dir%images\*.* %build_dir%

rem  delete scores file to reset highscores
del %build_dir%scores.txt
