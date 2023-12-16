#pragma once

#include <string>

namespace Lucy
{
  class Layer
  {
  public:
    Layer() = default;
    Layer(const std::string& name) : name_{name} {}

    Layer(const Layer&) = default;
    Layer(Layer&&) = default;
    Layer& operator=(const Layer&) = default;
    Layer& operator=(Layer&&) = default;
    virtual ~Layer() = default;

    virtual void init();
    virtual void update();
    virtual void render();
    virtual void shutdown();

  private:
    std::string name_;
  };
}
