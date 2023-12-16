workspace "LucyEngine_YT"
  location "./"
  architecture "x86_64"
  startproject "Sandbox"

  configurations
  {
    "Debug", "Release"
  }

  flags
  {
    "MultiProcessorCompile"
  }

  outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

include "vendor/glad"
include "vendor/glfw"
include "lucy/"
include "sandbox/"