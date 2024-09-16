-- Project NEURAL
project "NEURAL"
	kind "StaticLib" -- can be changed to StaticLib
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
	
	includedirs
	{
		"%{prj.location}/src/"
	}
	
	-- filters for compiler definitions
	filter "configurations:WinDEBUG"
		defines {"WINDOWS","DEBUG"}
	
	filter "configurations:WinRELEASE"
		defines {"WINDOWS","RELEASE"}
		
	filter "configurations:LinuxDEBUG"
		toolset "gcc"
		system "linux"
		--toolchainversion ("wsl2")
		defines {"LINUX","DEBUG"}
	
	filter "configurations:LinuxRELEASE"
		toolset "gcc"
		system "linux"
		--toolchainversion ("wsl2")
		defines {"LINUX","RELEASE"}
		
	-- Staticlib vs. SharedLib	
	filter "kind:SharedLib"
		defines {"BUILD_DLL"}
	
	

