@echo off
pushd "../"
call "premake/premake5.exe" vs2022
popd
PAUSE