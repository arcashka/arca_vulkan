#pragma once

#include "iwindow.h"

struct GLFWwindow;

namespace arca::core {

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