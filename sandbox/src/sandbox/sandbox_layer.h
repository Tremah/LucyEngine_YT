#pragma once

#include <lucy/core/layer.h>

namespace Sandbox
{
  class SandboxLayer : public Lucy::Layer
  {
  public:
    SandboxLayer() : Layer("SandboxLayer") {}

    void init() override;
    void update() override;
    void render() override;
    void shutdown() override;
  };

}