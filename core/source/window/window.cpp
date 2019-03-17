#include "window.h"

#include "coreBaseSettings.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace arca::core {

Window::Window()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(640, 480, settings::MAIN_WINDOW_NAME.data(), nullptr, nullptr);
}

Window::~Window()
{
	glfwDestroyWindow(window);
}

}