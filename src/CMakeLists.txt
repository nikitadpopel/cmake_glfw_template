cmake_minimum_required (VERSION 3.8)

add_library(src STATIC
    Main.cpp
)

target_include_directories(src PUBLIC 
                            src)
                            
add_executable (App
    Main.cpp
)

target_link_libraries(App glfw)
target_link_libraries(App glad)