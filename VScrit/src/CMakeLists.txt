set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(HEADER_FILES
    ${CMAKE_SOURCE_DIR}/VScrit/src/Render.h
    ${CMAKE_SOURCE_DIR}/VScrit/src/Layer.h
    ${CMAKE_SOURCE_DIR}/VScrit/src/Nodes/AddNode.h
    ${CMAKE_SOURCE_DIR}/VScrit/src/Nodes/BaseNode.h
    ${CMAKE_SOURCE_DIR}/VScrit/src/Nodes/InputNode.h
)

set(SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/VScrit/src/main.cpp
    ${CMAKE_SOURCE_DIR}/VScrit/src/Render.cpp
)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

if (WIN32)
    add_custom_command(
        TARGET VScrit POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy $<TARGET_FILE:SDL3::SDL3-shared> $<TARGET_FILE_DIR:VScrit>
        VERBATIM
    )
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
    ./    
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/imgui
    ${CMAKE_SOURCE_DIR}/VScrit/vendor/SDL/include
    ${CMAKE_SOURCE_DIR}/VScrit/src/Nodes
)

# target_sources(${PROJECT_NAME} PRIVATE 
#     ${CMAKE_SOURCE_DIR}/VScrit/src/main.cpp
#     ${CMAKE_SOURCE_DIR}/VScrit/src/Render.cpp

# )

target_link_libraries(${PROJECT_NAME} PRIVATE
    SDL3::SDL3
    Vulkan::Vulkan
    imgui
)