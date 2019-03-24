#include "core.h"

#include "iwindow.h"

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

	instance = new Core(initializer.window);
}

Core::Core(std::shared_ptr<window::IWindow> window)
	: window(window)
{
}

}