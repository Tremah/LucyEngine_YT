#pragma once

#include <cstdint>
#include <string>

#include <glad/gl.h>
#include <glfw/glfw3.h>


namespace Lucy
{
  class Window
  {
  public:
    Window(uint16_t width, uint16_t height, const std::string& title) : width_{width}, height_{height}, title_{title}{}

    GLFWwindow* init();
    bool initGlad();

    void shutdown();

    uint16_t getWidth();
    uint16_t getHeight();

    GLFWwindow* getNativeWindow();

  private:
    uint16_t width_ = 0;
    uint16_t height_ = 0;
    std::string title_{};

    GLFWwindow* nativeWindow_{nullptr};

  };
}
