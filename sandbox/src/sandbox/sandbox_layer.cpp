#include "sandbox_Layer.h"

#include <iostream>

#include <lucy/renderer/renderer.h>

namespace Sandbox
{
  void SandboxLayer::init()
  {
    std::cout << "SandboxLayer init\n";
  }

  void SandboxLayer::update()
  {
    //std::cout << "SandboxLayer update\n";
    Lucy::Renderer::draw();
  }

  void SandboxLayer::render()
  {
    std::cout << "SandboxLayer render\n";
  }

  void SandboxLayer::shutdown()
  {
    std::cout << "SandboxLayer shutdown\n";
  }
}