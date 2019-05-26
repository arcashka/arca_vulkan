#pragma once

#include <memory>

namespace arca::window {
	class IWindow;
}

namespace arca::core {
	class Core;
}

namespace arca::app {

class ArcaApplication
{
public:
	ArcaApplication();
	virtual ~ArcaApplication();
	virtual void run();

	static ArcaApplication * getInstance();

private:
	std::shared_ptr<core::Core> core;
	std::shared_ptr<window::IWindow> window;
};

}