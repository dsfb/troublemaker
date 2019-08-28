#include <glad/glad.h>

#include <GLFW/glfw3.h>

namespace tmk {
class window_context {
public:
  window_context();
  ~window_context();
  void render();

private:
  GLFWwindow *window_;
};
} // namespace tmk