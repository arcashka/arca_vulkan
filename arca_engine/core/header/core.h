#pragma once

#include <memory>

namespace arca::window {
	class IWindow;
}

namespace arca::core {

class Core
{
public:
	Core() = delete;
	Core(const Core &) = delete;
	Core & operator=(Core &) = delete;

	static std::shared_ptr<Core> getInstance();

	struct CoreInitializer
	{
		std::shared_ptr<window::IWindow> window;
	};

	static void initialize(const CoreInitializer & initializer);

private:
	Core(std::shared_ptr<window::IWindow> window);

private:
	std::shared_ptr<window::IWindow> window;
};

}
