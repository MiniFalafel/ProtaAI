@echo off
pushd "../"
call "setup/premake/premake5.exe" vs2022
popd
PAUSE
