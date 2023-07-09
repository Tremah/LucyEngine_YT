project "glfw"
	kind "StaticLib"
	language "C"
	architecture "x86_64"
  location ("./")

	targetdir ("%{wks.location}/bin/bin/" .. outputdir .. "/%{prj.name}")
  objdir    ("%{wks.location}/bin/bin-int/" .. outputdir .. "/%{prj.name}")
  debugdir ("./")
	
	includedirs { "include/" }

	filter "system:windows"
    cppdialect "C++20"
		systemversion "latest"
		staticruntime "On"

		files
		{
			"../../dependencies/%{prj.name}/src/*.c"
		}

		defines 
		{ 
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"