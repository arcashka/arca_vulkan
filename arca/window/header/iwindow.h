#pragma once

#include <memory>

namespace arca::window
{

class IWindow
{
public:
	static std::shared_ptr<IWindow> createWindow();

	virtual ~IWindow() {};
	virtual bool isReal() = 0; 
};

}
