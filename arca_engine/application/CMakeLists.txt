add_library(arcaApplication
	"${CMAKE_CURRENT_LIST_DIR}/source/arcaApplication.cpp"
)

target_link_libraries(arcaApplication
	window
	core
)

target_include_directories(arcaApplication
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/header"
)