-- Project SANDBOX
project "SANDBOX"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	
	-- output/bin dirs
	targetdir ("bin/" .. outdir .. "%{prj.name}")
	objdir ("bin-int/" .. outdir .. "%{prj.name}")
	
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