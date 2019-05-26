cmake_minimum_required(VERSION 3.13)
project (ArcaVulkan)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (EXISTS ${CMAKE_BINARY_DIR}/compile_commands.json)
	configure_file(${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/compile_commands.json)
endif()

set(ARCA_USE_GRAPHICAL_OUTPUT true)
set(ARCA_STATIC_SHADERS_FILE "${CMAKE_CURRENT_LIST_DIR}/shaders_list.txt")

add_subdirectory(arca_engine)

add_executable(arca
	"${PROJECT_SOURCE_DIR}/main.cpp"
)

target_link_libraries(arca
	arcaApplication
)
