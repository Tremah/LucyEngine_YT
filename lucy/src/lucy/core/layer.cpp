#include "layer.h"

#include <iostream>

namespace Lucy
{
  void Layer::init()
  {
    std::cout << "Engine Layer init!\n";
  }
  void Layer::update()
  {
  }
  void Layer::render()
  {
  }
  void Layer::shutdown()
  {
    std::cout << "Engine Layer shutdown!\n";
  }
}