if (ARCA_USE_GRAPHICAL_OUTPUT)
    find_package(glfw3 REQUIRED)
endif()

configure_file("${CMAKE_CURRENT_LIST_DIR}/coreBaseSettings.h.in" "${CMAKE_CURRENT_BINARY_DIR}/coreBaseSettings.h")
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

find_package(Vulkan)

add_library(core
	"${CMAKE_CURRENT_LIST_DIR}/source/core.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/source/window/iwindow.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/source/window/window.cpp"
)

if (DEFINED ARCA_STATIC_SHADERS_FILE)
    include("${CMAKE_CURRENT_LIST_DIR}/compile_shaders.cmake")
    add_compile_shaders_command(${ARCA_STATIC_SHADERS_FILE})
    add_dependencies(core compile_shaders) 
endif()