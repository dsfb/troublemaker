#ifndef TROUBLEMAKER_GRAPHICS_PIPELINE_H
#define TROUBLEMAKER_GRAPHICS_PIPELINE_H

#include <embedcpp/shaders/fragment.glsl.embed.hpp>
#include <embedcpp/shaders/vertex.glsl.embed.hpp>
#include <glad/glad.h>
#include <iostream>

unsigned int build_shader_program() {
  const GLchar *shader_strs[] = {embedcpp::vertex_glsl_c_arr};
  const GLint str_lens[] = {embedcpp::vertex_glsl_view.size()};
  unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, shader_strs, str_lens);
  glCompileShader(vertex_shader);
  int success;
  char infoLog[512];
  glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  const GLchar *fshader_strs[] = {embedcpp::fragment_glsl_c_arr};
  const GLint fstr_lens[] = {embedcpp::fragment_glsl_view.size()};
  glShaderSource(fragmentShader, 1, fshader_strs, fstr_lens);
  glCompileShader(fragmentShader);
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertex_shader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADERPROGRAM::LINK_FAILED\n" << infoLog << std::endl;
  }
  glUseProgram(shaderProgram);
  glDeleteShader(vertex_shader);
  glDeleteShader(fragmentShader);
  return shaderProgram;
}

unsigned int make_vertex_array_object() {
  float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};
  unsigned int VBO;
  glGenBuffers(1, &VBO);
  unsigned int VAO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  return VAO;
}

#endif
