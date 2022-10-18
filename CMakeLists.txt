cmake_minimum_required (VERSION 3.8)

project (src)

add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory ("src")

target_include_directories(src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include)
target_include_directories(src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/build/glad/include)