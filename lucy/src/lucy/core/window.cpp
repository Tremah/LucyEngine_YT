#include "window.h"

#include <iostream>

namespace Lucy
{
  GLFWwindow* Window::init()
  {
    //Init GLFW and create window
    if (!glfwInit())
    {
      std::cout << "GLFW init failed!\n";
      return nullptr;
    }
    std::cout << "GLFW init successful!\n";

    nativeWindow_ = glfwCreateWindow(1600, 900, "Hello YT Window", nullptr, nullptr);
    glfwMakeContextCurrent(nativeWindow_);

    return nativeWindow_;
  }

  void Window::shutdown()
  {
    glfwDestroyWindow(nativeWindow_);
    glfwTerminate();
  }

  uint16_t Window::getWidth()
  {
    return width_;
  }

  uint16_t Window::getHeight()
  {
    return height_;
  }
}
