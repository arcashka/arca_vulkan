#pragma once

#include "iwindow.h"

struct GLFWwindow;

namespace arca::window {

class Window : public IWindow
{
public:
	Window();
	~Window() override;

	bool isReal() override { return true; }

private:
	GLFWwindow * window;
};

}