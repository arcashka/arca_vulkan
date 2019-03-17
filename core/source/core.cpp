#include "core.h"

#include "window/iwindow.h"

#include <assert.h>

namespace arca::core {

namespace {
	static Core * instance = nullptr;
}

Core * Core::getInstance()
{
	assert(instance && "initialize must be called before getting instance!");
	return instance;
}

void Core::initialize(const CoreInitializer & initializer)
{
	assert(!instance && "initialize must be called once!");

	std::shared_ptr<IWindow> window = IWindow::createWindow();

	instance = new Core(window);
}

Core::Core(std::shared_ptr<IWindow> window)
	: window(window)
{
}

}