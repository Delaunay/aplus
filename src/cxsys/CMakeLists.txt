

# better way ?
INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(..)

file(GLOB CXSYS_SRC *.c)
file(GLOB CXSYS_HDS *.h)

# main library (prevent recompilation when building tests)
ADD_LIBRARY(cxsys SHARED ${CXSYS_HDS} ${CXSYS_SRC})
TARGET_LINK_LIBRARIES(cxsys PUBLIC dap)
SET_PROPERTY(TARGET cxsys PROPERTY CXX_STANDARD 11)
