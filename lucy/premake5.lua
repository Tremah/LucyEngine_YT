project "LucyEngine"
	kind "ConsoleApp"
	language "C++"
  --Where the project file is placed
  location ("./")
  
  --Directories for the output of the compile and build process
  targetdir ("%{wks.location}/bin/bin/" .. outputdir .. "/%{prj.name}")
  objdir    ("%{wks.location}/bin/bin-int/" .. outputdir .. "/%{prj.name}")
  debugdir  ("./")

  includedirs
  {
    "src/",
    "../vendor/glad/include/",
    "../vendor/glfw/include/"
  }
  
  files
  {
    "../*.h",
    "../*.cpp",    
    "src/**.h",
    "src/**.hpp",
    "src/**.cpp",  
    "src/**.inl",  
  } 

  links { "glad", "glfw"}

  filter "system:windows"
    cppdialect "C++20"
    staticruntime "on"
    systemversion "latest"
  
  filter "configurations:Debug"
    defines "LU_DEBUG=1"
    defines "LU_PROFILING=1"
    symbols "On"
  
  filter "configurations:Release"
    defines "LU_RELEASE=1"
    defines "LU_DEBUG=0"
    defines "LU_PROFILING=0"
    symbols "On"