set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O3 -Wall -Wextra -DDEBUG")

# sources
# basic math modules
set(BASIC_SRC basicmath.c vec.c point.c line.c polygon.c)
set(MINUTIAE_SRC minutiae.c minutiaset.c)
set(FINGERPRINT_SRC fingerprint.c fingerprintset.c)
set(SOURCE ${BASIC_SRC} ${MINUTIAE_SRC} ${FINGERPRINT_SRC})
set(SOURCE ${SOURCE} secondaryfeature.c similarity.c)

# headers
set(MINUTIAE_HEADER minutiae.h minutiaset.h)
set(FINGERPRINT_HEADER fingerprint.h fingerprintset.h)
set(HEADER common.c ${MINUTIAE_HEADER} ${FINGERPRINT_HEADER})
set(HEADER ${HEADER} secondaryfeature.h similarity.h)

add_library(fm ${SOURCE} ${HEADER})
target_link_libraries(fm m)
