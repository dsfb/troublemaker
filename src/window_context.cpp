#include <stdexcept>
#include <troublemaker/graphics_pipeline.hpp>
#include <troublemaker/window_context.hpp>

namespace {
const float initRed = 0.2f;
const float initGreen = 0.3f;
const float initBlue = 0.3f;
const float initAlpha = 1.0f;
const int initWindowWidth = 800;
const int initWindowHeight = 600;

void framebuffer_size_callback(GLFWwindow *, int width, int height) {
  glViewport(0, 0, width, height);
}

void process_input(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

void init_glfw() {
  if (glfwInit() == GLFW_FALSE) {
    throw std::runtime_error("Failed to init GLFW");
  }
}

void set_window_hints() {
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow *create_glfw_window() {
  auto window = glfwCreateWindow(initWindowWidth, initWindowHeight,
                                 "LearnOpenGL", nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    throw std::runtime_error("Failed to create GLFW window");
  }
  return window;
}

void link_opengl() {
  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    glfwTerminate();
    throw std::runtime_error("Failed to initialize GLAD");
  }
}
} // namespace

namespace tmk {
window_context::window_context() {
  init_glfw();
  set_window_hints();
  window_ = create_glfw_window();
  glfwMakeContextCurrent(window_);
  link_opengl();
  glViewport(0, 0, initWindowWidth, initWindowHeight);
  glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);
  shader_program_ = build_shader_program();
  VAO_ = make_vertex_array_object();
}

window_context::~window_context() { glfwTerminate(); }

void window_context::run_render_loop() {
  while (!glfwWindowShouldClose(window_)) {
    do_render();
  }
}

void window_context::do_render() {
  process_input(window_);
  glClearColor(initRed, initGreen, initBlue, initAlpha);
  glClear(GL_COLOR_BUFFER_BIT);
  glUseProgram(shader_program_);
  glBindVertexArray(VAO_);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glfwPollEvents();
  glfwSwapBuffers(window_);
}
} // namespace tmk
