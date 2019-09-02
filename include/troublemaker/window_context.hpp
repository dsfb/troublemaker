#ifndef TROUBLEMAKER_WINDOW_CONTEXT_H
#define TROUBLEMAKER_WINDOW_CONTEXT_H

#include <glad/glad.h>

#include <GLFW/glfw3.h>

namespace tmk {
class window_context {
public:
  window_context();
  ~window_context();
  void run_render_loop();

private:
  void do_render();
  GLFWwindow *window_;
  unsigned int shader_program_;
  unsigned int VAO_;
};
} // namespace tmk

#endif
