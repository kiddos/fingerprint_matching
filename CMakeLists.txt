cmake_minimum_required(VERSION 3.2)

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})
enable_testing()
add_subdirectory(src)
add_subdirectory(test)
