# Add target "compile_shaders" to compile shaders from "ALL_SHADERS_FILE" file
# ALL_SHADERS_FILE must contain paths to shaders relative to "CMAKE_SOURCE_DIR"

function(add_compile_shaders_command ALL_SHADERS_FILE)

    if (NOT WIN32)
        message(ERROR "NOT IMPLEMENTED")
        return()
    endif()

    set(SHADERS_DIR "${CMAKE_CURRENT_BINARY_DIR}/shaders")
    set(COMPILE_SHADERS_FILE "${SHADERS_DIR}/compile_shaders.bat")
    file(REMOVE_RECURSE "${SHADERS_DIR}")

    file(STRINGS "${ALL_SHADERS_FILE}" ALL_STATIC_SHADERS_LIST)
    get_filename_component(VULKAN_SDK_DIR ${Vulkan_INCLUDE_DIRS} DIRECTORY)

    foreach(SHADER ${ALL_STATIC_SHADERS_LIST})
        file(APPEND ${COMPILE_SHADERS_FILE}
            "${VULKAN_SDK_DIR}/Bin32/glslangValidator.exe -V ${CMAKE_SOURCE_DIR}/${SHADER}\n"
        )
    endforeach()
    file(APPEND ${COMPILE_SHADERS_FILE} "pause")

    add_custom_target(compile_shaders
        COMMAND cmd /c "${COMPILE_SHADERS_FILE}"
        WORKING_DIRECTORY "${SHADERS_DIR}"
    )

endfunction(add_compile_shaders_command)