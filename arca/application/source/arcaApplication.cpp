#include "arcaApplication.h"

#include <assert.h>
#include <iostream>

#include "core.h"
#include "iwindow.h"

namespace arca::app {

static ArcaApplication * instance;

ArcaApplication::ArcaApplication()
{
	assert(!instance && "ArcaApplication must be created once");

	window = window::IWindow::createWindow();

	core::Core::CoreInitializer initializer { window };
	core::Core::initialize(initializer);
	core = core::Core::getInstance();
}

ArcaApplication::~ArcaApplication()
{
}

ArcaApplication * ArcaApplication::getInstance()
{
	if (instance)
		return instance;

	instance = new ArcaApplication();
	return instance;
}

void ArcaApplication::run()
{
	std::cout << "pew" << std::endl;
}

}