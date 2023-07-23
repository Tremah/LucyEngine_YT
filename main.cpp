#include <iostream>
#include <string>
#include <vector>

#include <glad/gl.h>
#include <glfw/glfw3.h>

#include <lucy/core/window.h>
#include <lucy/renderer/renderer.h>

bool initGlad()
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

int main()
{  
  Lucy::Window window{1600, 900, "LucyEngine"};

  auto glfwWindow = window.init();

  if (!glfwWindow)
  {
    return 1;
  }

  if (!initGlad())
  {
    return 1;
  }

  glViewport(0, 0, window.getWidth(), window.getHeight());

  Lucy::Renderer::init();

  while (!glfwWindowShouldClose(glfwWindow))
  {
    glfwPollEvents();

    Lucy::Renderer::draw(glfwWindow);

    if (glfwGetKey(glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
      break;
    }
  }

  window.shutdown();
  return 0; 
} 
