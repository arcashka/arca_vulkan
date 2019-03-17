#pragma once

#include "iwindow.h"

namespace arca::core {

class Window : public IWindow
{
public:
	Window();
	~Window() override;

	bool isReal() override { return true; }
};

}