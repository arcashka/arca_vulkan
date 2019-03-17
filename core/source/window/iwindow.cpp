#include "iwindow.h"
#include "window.h"

#include "coreBaseSettings.h"

namespace arca::core
{

std::shared_ptr<IWindow> IWindow::createWindow()
{
	if (settings::USE_GRAPHICAL_OUTPUT)
		return std::make_shared<Window>();
	else
		return std::make_shared<FakeWindow>();
}

}