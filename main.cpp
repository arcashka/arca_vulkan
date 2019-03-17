#include "core/source/core.h"

int main()
{
	arca::core::Core::CoreInitializer initializer;
	arca::core::Core::initialize(initializer);
	arca::core::Core * core = arca::core::Core::getInstance();
	return 0;
}