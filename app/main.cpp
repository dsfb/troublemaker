#include <iostream>
#include <troublemaker/window_context.hpp>

int main() {
  try {
    tmk::window_context window_ctx;
    window_ctx.run_render_loop();
  } catch (const std::exception &e) {
    std::cout << "Expection caught on main: " << e.what() << std::endl;
  }
  return 0;
}