configure_file("${CMAKE_CURRENT_SOURCE_DIR}/windowBaseSettings.h.in" "${CMAKE_BINARY_DIR}/include/window/windowBaseSettings.h")
find_package(Vulkan REQUIRED)

if (ARCA_USE_GRAPHICAL_OUTPUT)
	find_package(glfw3 REQUIRED)

	add_library(window
		"${CMAKE_CURRENT_LIST_DIR}/source/iwindow.cpp"
		"${CMAKE_CURRENT_LIST_DIR}/source/window.cpp"
	)

	target_link_libraries(window
		${Vulkan_LIBRARY}
		glfw
		${GLFW_LIBRARIES}
	)

	target_include_directories(window
		PUBLIC
			"${CMAKE_CURRENT_LIST_DIR}/header"
		PRIVATE
			"${CMAKE_BINARY_DIR}/include/window"
			"${GLFW_INCLUDE_DIR}"
			"${Vulkan_INCLUDE_DIRS}"
			"${CMAKE_CURRENT_BINARY_DIR}"
	)

	target_compile_definitions(window
		PRIVATE USE_GRAPHICAL_OUTPUT
	)
else()
	add_library(window
		"${CMAKE_CURRENT_LIST_DIR}/source/iwindow.cpp"
	)

	target_link_libraries(window
		"${Vulkan_LIBRARY}"
	)

	target_include_directories(window
		PUBLIC
			"${CMAKE_CURRENT_LIST_DIR}/header"
		PRIVATE
			"${Vulkan_INCLUDE_DIRS}"
			"${CMAKE_CURRENT_BINARY_DIR}/include/window"
	)
endif()
