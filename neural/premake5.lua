-- Project NEURAL
project "NEURAL"
	kind "SharedLib" -- can be changed to StaticLib
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
		
	-- Staticlib vs. SharedLib	
	filter "kind:SharedLib"
		defines {"BUILD_SHARED"}
	
	