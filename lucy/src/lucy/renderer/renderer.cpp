#include "renderer.h"

#include <iostream>
#include <vector>

namespace Lucy
{
  struct RenderStorage
  {
    RenderStorage() = default;   
    uint32_t vertexArray_ = 0;
    uint32_t vertexBuffer_ = 0;
    uint32_t shader_ = 0;

    std::vector<float> vertices_
    {
      -0.5f, -0.5f,  
      0.5f, -0.5f,
      0.f, 0.4f
    };

  };

  static RenderStorage s_renderStorage;

  void Renderer::init()
  {
    glGenVertexArrays(1, &s_renderStorage.vertexArray_);
    glGenBuffers(1, &s_renderStorage.vertexBuffer_);

    glBindVertexArray(s_renderStorage.vertexArray_);
    glBindBuffer(GL_ARRAY_BUFFER, s_renderStorage.vertexBuffer_);

    uint32_t numberOfVertices = 3;
    uint32_t componentsPerVertex = 2;

    glBufferData(GL_ARRAY_BUFFER, numberOfVertices * componentsPerVertex * sizeof(float), nullptr, GL_STATIC_DRAW);

    uint32_t attributeId = 0;
    glVertexAttribPointer(attributeId, componentsPerVertex, GL_FLOAT, GL_FALSE, componentsPerVertex * sizeof(float), (void*)0);
    glEnableVertexAttribArray(attributeId);

    //Vertex
    const char* vertexShaderCode =
      "#version 460 core\n"
      "layout (location = 0) in vec2 inPos;\n"
      "void main()\n"
      "{\n"
      "  gl_Position = vec4(inPos.x, inPos.y, 1.f, 1.f);\n"
      "}\0";

    uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderCode, nullptr);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
      glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"<< infoLog << std::endl;
    }
       
    //Fragment
    const char* fragmentShaderCode =
      "#version 460 core\n"
      "out vec4 outColor;"

      "void main()\n"
      "{\n"
      "outColor = vec4(0.9f, 0.3f, 0.3f, 1.0f);\n"
      "}\0";

    uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderCode, nullptr);
    glCompileShader(fragmentShader);

    success = 0;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    
    if (!success)
    {
      glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
      std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //Create and link shader program
    s_renderStorage.shader_ = glCreateProgram();
    glAttachShader(s_renderStorage.shader_, vertexShader);
    glAttachShader(s_renderStorage.shader_, fragmentShader);
    glLinkProgram(s_renderStorage.shader_);

    success = 0;
    glGetProgramiv(s_renderStorage.shader_, GL_LINK_STATUS, &success);
    if (!success)
    {
      glGetProgramInfoLog(s_renderStorage.shader_, 512, nullptr, infoLog);
      std::cout << "ERROR::SHADER::LINKAGE_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
  }

  void Renderer::draw()
  {
    glClearColor(0.2f, 0.2f, 0.2f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(s_renderStorage.shader_);

    glBufferData(GL_ARRAY_BUFFER, 3 * 2 * sizeof(float), s_renderStorage.vertices_.data(), GL_STATIC_DRAW);

    glDrawArrays(GL_TRIANGLES, 0, 3);

  }

}
