set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O3 -Wall -Wextra -DDEBUG")

# sources
# basic math modules
set(BASIC_SRC basicmath.c vec.c point.c line.c polygon.c)
set(MINUTIAE_SRC minutiae.c minutiaset.c)
set(FINGERPRINT_SRC fingerprint.c fingerprintset.c)
set(MATCHING_SRC similarity.c)
set(SECONDARY_SRC secondaryfeature.c secondaryfeatureset.c)
set(SOURCE ${BASIC_SRC} ${MINUTIAE_SRC} ${FINGERPRINT_SRC})
set(SOURCE ${SOURCE} ${SECONDARY_SRC} ${MATCHING_SRC})

# headers
set(MINUTIAE_HEADER minutiae.h minutiaset.h)
set(FINGERPRINT_HEADER fingerprint.h fingerprintset.h)
set(MATCHING_HEADER similarity.h)
set(SECONDARY_HEADER secondaryfeature.h secondaryfeatureset.h)
set(HEADER common.h ${MINUTIAE_HEADER} ${FINGERPRINT_HEADER})
set(HEADER ${HEADER} ${SECONDARY_HEADER} ${MATCHING_HEADER})

add_library(fm ${SOURCE} ${HEADER})
target_link_libraries(fm m)
