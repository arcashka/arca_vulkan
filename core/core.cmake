set (CORE_SOURCE
	"${CMAKE_CURRENT_LIST_DIR}/source/core.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/source/window/iwindow.cpp"
)

set (CORE_LIBS
	${Vulkan_LIBRARY}
)

if (ARCA_USE_GRAPHICAL_OUTPUT)
	find_package(glfw3 REQUIRED)
	include_directories(${GLFW_INCLUDE_DIR})

	set (CORE_SOURCE
		${CORE_SOURCE}
		"${CMAKE_CURRENT_LIST_DIR}/source/window/window.cpp"
	)

	set (CORE_LIBS
		${CORE_LIBS}
		glfw
		${GLFW_LIBRARIES}
	)

	set (CORE_DEFINES
		USE_GRAPHICAL_OUTPUT
	)
endif()

configure_file("${CMAKE_CURRENT_LIST_DIR}/coreBaseSettings.h.in" "${CMAKE_CURRENT_BINARY_DIR}/coreBaseSettings.h")
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

find_package(Vulkan REQUIRED)
include_directories(${Vulkan_INCLUDE_DIRS})

add_library(core
	${CORE_SOURCE}
)

target_compile_definitions(core
	PRIVATE ${CORE_DEFINES}
)

target_link_libraries(core
	${CORE_LIBS}
)

if (DEFINED ARCA_STATIC_SHADERS_FILE)
	include("${CMAKE_CURRENT_LIST_DIR}/compile_shaders.cmake")
	add_compile_shaders_command(${ARCA_STATIC_SHADERS_FILE})
	add_dependencies(core compile_shaders) 
endif()