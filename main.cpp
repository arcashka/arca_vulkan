#include "arca/application/header/arcaApplication.h"

int main()
{
	auto * app = arca::app::ArcaApplication::getInstance();
	app->run();
}