#pragma once

#include <glad/gl.h>
#include <glfw/glfw3.h>

namespace Lucy
{
  class Renderer
  {
  public:
    Renderer() = default;

    static void init();

    static void draw();
  };
}