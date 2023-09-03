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

    glfwSetKeyCallback(nativeWindow_, [](GLFWwindow* window, int key, int action, int scancode, int mods)
      {
        std::cout << "GLFW Key Callback!\n";
      });

    glfwSetMouseButtonCallback(nativeWindow_, [](GLFWwindow* window, int button, int action, int mods)
      {
        std::cout << "GLFW Mouse Callback!\n";
      });

    return nativeWindow_;
  }

  bool Window::initGlad()
  {
    //Init glad
    int gladState = gladLoadGL(glfwGetProcAddress);
    if (!gladState)
    {
      //If not successful, terminate GLFW
      std::cout << "ERROR: Could not init glad!\n";
      return false;
    }
    std::cout << "GLAD init successful!\n";

    return true;
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

  GLFWwindow* Window::getNativeWindow()
  {
    return nativeWindow_;
  }
}
