set(SOURCE ../src/minutiae.c ../src/common.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDEBUG -fPIC -Wall -Wextra -O2 -g")

include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(minutiae_test minutiae_test.c ${SOURCE})

target_link_libraries(minutiae_test m)

add_test(minutiae_test ./minutiae_test)
