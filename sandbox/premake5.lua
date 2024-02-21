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
	
	-- filters for compiler definitions
	filter "configurations:WinDEBUG"
		symbols "on"
		defines {"WINDOWS","DEBUG"}
	
	filter "configurations:WinRELEASE"
		optimize "on"
		defines {"WINDOWS","RELEASE"}
		
	filter "configurations:LinuxDEBUG"
		symbols "on"
		toolset "gcc"
		system "linux"
		toolchainversion ("wsl2")
		defines {"LINUX","DEBUG"}
	
	filter "configurations:LinuxRELEASE"
		optimize "on"
		toolset "gcc"
		system "linux"
		toolchainversion ("wsl2")
		defines {"LINUX","RELEASE"}