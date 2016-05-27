set(SOURCE common.c minutiae.c minutiaset.c secondaryfeature.c)
set(HEADER common.h minutiae.h minutiaset.h secondaryfeature.h)

add_library(fm ${SOURCE})
