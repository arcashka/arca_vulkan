#include "iwindow.h"

#if defined USE_GRAPHICAL_OUTPUT
#include "window.h"
#endif

#include "coreBaseSettings.h"

namespace arca::core
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