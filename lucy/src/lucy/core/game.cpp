#include "game.h"
#include <iostream>
#include <lucy/renderer/renderer.h>

void Lucy::Game::start()
{
  auto glfwWindow = window_.init();

  if (!glfwWindow)
  {
    std::cout << "GLFW init failed!";
  }

  if (!window_.initGlad())
  {
    std::cout << "GLAD init failed!";
  }

  glViewport(0, 0, window_.getWidth(), window_.getHeight());

  Lucy::Renderer::init();
}

void Lucy::Game::run()
{
  running_ = true;

  while (running_)
  {
    glfwPollEvents();


    Lucy::Renderer::draw();

    glfwSwapBuffers(window_.getNativeWindow());

    if (glfwGetKey(window_.getNativeWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(window_.getNativeWindow()))
    {
      running_ = false;
    }
  }
}

void Lucy::Game::shutdown()
{
  window_.shutdown();
}
