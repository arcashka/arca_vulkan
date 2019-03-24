#include "core.h"

#include <assert.h>

#include "iwindow.h"

namespace arca::core {

namespace {
	static std::shared_ptr<Core> instance = nullptr;
}

std::shared_ptr<Core> Core::getInstance()
{
	assert(instance && "initialize must be called before getting instance!");
	return instance;
}

void Core::initialize(const CoreInitializer & initializer)
{
	assert(!instance && "initialize must be called once!");

	instance = std::shared_ptr<Core>(new Core(initializer.window));
}

Core::Core(std::shared_ptr<window::IWindow> window)
	: window(window)
{
}

}