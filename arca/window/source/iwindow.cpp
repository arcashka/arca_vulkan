#include "iwindow.h"

#if defined USE_GRAPHICAL_OUTPUT
#include "window.h"
#endif

#include "windowBaseSettings.h"

namespace arca::window
{

std::shared_ptr<IWindow> IWindow::createWindow()
{
#if defined USE_GRAPHICAL_OUTPUT
	return std::make_shared<Window>();
#else
	return std::make_shared<FakeWindow>();
#endif
}

}