#pragma once

namespace arca::core {

class Core
{
private:
	Core() {}
	Core(const Core &) {}
	Core & operator=(Core &) {}

public:
	static Core * getInstance();

	struct CoreInitializer {};
	static void initialize(const CoreInitializer & initializer);
};

}