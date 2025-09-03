set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME})

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