set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME})

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
)

target_sources(${PROJECT_NAME} PRIVATE 
    main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    SDL3::SDL3
    Vulkan::Vulkan
    imgui
)