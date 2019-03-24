#include "arca/core/source/core.h"
#include "arca/window/header/iwindow.h"

int main()
{
	std::shared_ptr<arca::window::IWindow> window = arca::window::IWindow::createWindow();
	arca::core::Core::CoreInitializer initializer { window };
	arca::core::Core::initialize(initializer);
	
	return 0;
}