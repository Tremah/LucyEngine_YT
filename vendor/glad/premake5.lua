project "glad"
	kind "StaticLib"
	language "C"
	architecture "x86_64"
  location ("./")

	targetdir ("%{wks.location}/bin/bin/" .. outputdir .. "/%{prj.name}")
  objdir    ("%{wks.location}/bin/bin-int/" .. outputdir .. "/%{prj.name}")
  --Working directory for the debugger
  debugdir ("./")

  includedirs {"include/"}

  files {"../../dependencies/%{prj.name}/src/gl.c"}

  filter "system:windows"
    cppdialect "C++20"
		systemversion "latest"    
    --set runtime library to multithreaded
		staticruntime "On"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		symbols "on"
    optimize "Full"