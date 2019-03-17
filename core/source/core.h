#pragma once

#include <memory>

namespace arca::core {

class IWindow;

class Core
{
public:
	static Core * getInstance();

	struct CoreInitializer {};
	static void initialize(const CoreInitializer & initializer);

private:
	Core() {}
	Core(std::shared_ptr<IWindow> window);
	Core(const Core &) {}
	Core & operator=(Core &) {}

private:
	std::shared_ptr<IWindow> window;
};

}