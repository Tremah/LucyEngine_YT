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

  for (auto layer : layers_)
  {
    layer->init();
  }
} 

void Lucy::Game::run()
{
  running_ = true;

  while (running_)
  {
    glfwPollEvents();

    for (auto layer : layers_)
    {
      layer->update();
    }

    glfwSwapBuffers(window_.getNativeWindow());

    if (glfwGetKey(window_.getNativeWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(window_.getNativeWindow()))
    {
      running_ = false;
    }
  }
}

void Lucy::Game::shutdown()
{
  for (auto layer : layers_)
  {
    layer->shutdown();
    delete layer;
  }
  window_.shutdown();
}

void Lucy::Game::addLayer(Layer* layer)
{
  layers_.emplace_back(layer);
}
