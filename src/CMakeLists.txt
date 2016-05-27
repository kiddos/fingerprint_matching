set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O3 -Wall -Wextra -DDEBUG")
set(SOURCE common.c minutiae.c minutiaset.c secondaryfeature.c)
set(HEADER common.h minutiae.h minutiaset.h secondaryfeature.h)

add_library(fm ${SOURCE})
target_link_libraries(fm m)
