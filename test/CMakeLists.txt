set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDEBUG -fPIC -Wall -Wextra -O2 -g")
set(LIBS m fm)

include_directories(${CMAKE_SOURCE_DIR}/src)
link_directories(${CMAKE_BINARY_DIR}/src)
add_executable(minutiae_test minutiae_test.c)
add_executable(secondaryfeature_test secondaryfeature_test.c)
add_executable(minutiaset_test minutiaset_test.c)
add_executable(fingerprint_test fingerprint_test.c)
add_executable(fingerprintset_test fingerprintset_test.c)
add_executable(fingerprint_secondary_feature_test
    fingerprint_secondary_feature_test.c)

target_link_libraries(minutiae_test ${LIBS})
target_link_libraries(secondaryfeature_test ${LIBS})
target_link_libraries(minutiaset_test ${LIBS})
target_link_libraries(fingerprint_test ${LIBS})
target_link_libraries(fingerprintset_test ${LIBS})
target_link_libraries(fingerprint_secondary_feature_test ${LIBS})

add_test(minutiae_test ${CMAKE_BINARY_DIR}/test/minutiae_test)
add_test(secondaryfeature_test ${CMAKE_BINARY_DIR}/test/secondaryfeature_test)
add_test(minutiaset_test ${CMAKE_BINARY_DIR}/test/minutiaset_test)
add_test(fingerprint_test ${CMAKE_BINARY_DIR}/test/fingerprint_test)
add_test(fingerprintset_test ${CMAKE_BINARY_DIR}/test/fingerprintset_test)
add_test(fingerprint_secondary_feature_test
    ${CMAKE_BINARY_DIR}/test/fingerprint_secondary_feature_test)
