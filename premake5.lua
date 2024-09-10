-- Workspace
workspace "PROTA"
	architecture "x86_64"
	
	configurations
	{
		"WinDEBUG",
		"WinRELEASE",
		"LinuxDEBUG",
		"LinuxRELEASE",
	}
	
	startproject "SANDBOX"
	
-- bin directory
outdir = "%{cfg.buildcfg}-%{cfg.architecture}/"

-- projects
include "neural/premake5"
include "sandbox/premake5"