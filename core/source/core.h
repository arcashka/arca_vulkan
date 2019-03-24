#pragma once

#include <memory>

namespace arca::window {
	class IWindow;
}

namespace arca::core {

class Core
{
public:
	static Core * getInstance();

	struct CoreInitializer
	{
		std::shared_ptr<window::IWindow> window;
	};

	static void initialize(const CoreInitializer & initializer);

private:
	Core() {}
	Core(std::shared_ptr<window::IWindow> window);
	Core(const Core &) {}
	Core & operator=(Core &) {}

private:
	std::shared_ptr<window::IWindow> window;
};

}