#pragma once

#include <cstdint>
#include <string>

#include <glfw/glfw3.h>


namespace Lucy
{
  class Window
  {
  public:
    Window(uint16_t width, uint16_t height, const std::string& title) : width_{width}, height_{height}, title_{title}{}

    GLFWwindow* init();
    void shutdown();

    uint16_t getWidth();
    uint16_t getHeight();

  private:
    uint16_t width_;
    uint16_t height_;
    std::string title_;

    GLFWwindow* nativeWindow_;

  };
}
