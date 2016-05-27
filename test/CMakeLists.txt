set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDEBUG -fPIC -Wall -Wextra -O2 -g")
set(LIBS m fm)

include_directories(${CMAKE_SOURCE_DIR}/src)
link_directories(${CMAKE_BIN_DIR}/src)
add_executable(minutiae_test minutiae_test.c)
add_executable(secondaryfeature_test secondaryfeature_test.c)
add_executable(minutiaset_test minutiaset_test.c)

target_link_libraries(minutiae_test ${LIBS})
target_link_libraries(secondaryfeature_test ${LIBS})
target_link_libraries(minutiaset_test ${LIBS})

add_test(minutiae_test ./minutiae_test)
add_test(secondaryfeature_test ./secondaryfeature_test)
add_test(minutiaset_test ./minutiaset_test)
