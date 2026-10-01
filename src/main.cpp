#include <iostream>

#include "GLFW/glfw3.h"

void error_callback(int error, const char *description) {
  std::cout << "GLFW Error (" << error << "): " << description << "\n";
}

int main() {
  glfwSetErrorCallback(error_callback);

  if (!glfwInit()) {
    std::cerr << "GLFW initialization failed";
    return 1;
  }

  GLFWwindow *window{glfwCreateWindow(700, 700, "Window", nullptr, nullptr)};
  if (!window) {
    std::cerr << "Unable to create window";
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
