-- Project SANDBOX
project "SANDBOX"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	
	-- output/bin dirs
	targetdir ("%{prj.location}/bin/" .. outdir .. "%{prj.name}")
	objdir ("%{prj.location}/bin/int/" .. outdir .. "%{prj.name}")
	
	files
	{
		"src/**.h",
		"src/**.cpp"
	}
	
	-- Link to NEURAL sharedlib
	links
	{
		"NEURAL"
	}
	
	includedirs
	{
		"../neural/src"
	}