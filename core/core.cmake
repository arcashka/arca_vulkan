if (ARCA_USE_GRAPHICAL_OUTPUT)
    find_package(glfw3 REQUIRED)
endif()

find_package(Vulkan)

add_library(core
    "${CMAKE_CURRENT_LIST_DIR}/source/core.cpp"
)

if (DEFINED ARCA_STATIC_SHADERS_FILE)
    include("${CMAKE_CURRENT_LIST_DIR}/compile_shaders.cmake")
    add_compile_shaders_command(${ARCA_STATIC_SHADERS_FILE})
    add_dependencies(core compile_shaders)
endif()