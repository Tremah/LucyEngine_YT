#include <iostream>
#include <string>
#include <vector>

#include <glad/gl.h>
#include <glfw/glfw3.h>

#include <lucy/renderer/renderer.h>

GLFWwindow* initGlfwAndGlad()
{
  //Init GLFW and create window
  if (!glfwInit())
  {
    std::cout << "GLFW init failed!\n";
    return nullptr;
  }
  std::cout << "GLFW init successful!\n";

  auto glfwWindow = glfwCreateWindow(1600, 900, "Hello YT Window", nullptr, nullptr);
  glfwMakeContextCurrent(glfwWindow);

  //Init glad
  int gladState = gladLoadGL(glfwGetProcAddress);
  if (!gladState)
  {
    //If not successful, terminate GLFW
    std::cout << "ERROR: Could not init glad!\n";
    glfwDestroyWindow(glfwWindow);
    glfwTerminate();
    return nullptr;
  }
  std::cout << "GLAD init successful!\n";

  glViewport(0, 0, 1600, 900);
  

  return glfwWindow;
}

int main()
{
  auto glfwWindow = initGlfwAndGlad();

  Lucy::Renderer::init();
  Lucy::Renderer::draw(glfwWindow);  

  int x = 0;
  std::cin >> x;

  return 0; 
} 


//GLAD Link: https://gen.glad.sh/