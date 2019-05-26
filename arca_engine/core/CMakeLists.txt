configure_file("${CMAKE_CURRENT_SOURCE_DIR}/coreBaseSettings.h.in" "${CMAKE_BINARY_DIR}/include/core/coreBaseSettings.h")

find_package(Vulkan REQUIRED)

add_library(core
	"${CMAKE_CURRENT_LIST_DIR}/source/core.cpp"
)

target_include_directories(core
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/header"
	PRIVATE
		"${Vulkan_INCLUDE_DIRS}"
		"${CMAKE_CURRENT_LIST_DIR}/source"
		"${CMAKE_CURRENT_BINARY_DIR}/include/core"
		"${WINDOW_LIB_HEADERS}"
)

target_link_libraries(core
	${Vulkan_LIBRARY}
)

if (DEFINED ARCA_STATIC_SHADERS_FILE)
	include("${CMAKE_CURRENT_LIST_DIR}/compile_shaders.cmake")
	add_compile_shaders_command(${ARCA_STATIC_SHADERS_FILE})
	add_dependencies(core compile_shaders) 
endif()
