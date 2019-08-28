#include <stdexcept>
#include <troublemaker/window_context.hpp>

namespace {
void framebuffer_size_callback(GLFWwindow *, int width, int height) {
  glViewport(0, 0, width, height);
}
} // namespace

namespace tmk {
window_context::window_context() {
  const auto initWindowWidth = 800;
  const auto initWindowHeight = 600;
  if (glfwInit() == GLFW_FALSE) {
    throw std::runtime_error("Failed to init GLFW");
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window_ = glfwCreateWindow(initWindowWidth, initWindowHeight, "LearnOpenGL",
                             nullptr, nullptr);
  if (!window_) {
    glfwTerminate();
    throw std::runtime_error("Failed to create GLFW window");
  }
  glfwMakeContextCurrent(window_);

  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    glfwTerminate();
    throw std::runtime_error("Failed to initialize GLAD");
  }

  glViewport(0, 0, initWindowWidth, initWindowHeight);

  glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);
}

window_context::~window_context() { glfwTerminate(); }

void window_context::render() {
  while (!glfwWindowShouldClose(window_)) {
    glfwSwapBuffers(window_);
    glfwPollEvents();
  }
}
} // namespace tmk
