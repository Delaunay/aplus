

# better way ?
INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(..)

file(GLOB CXC_SRC *.c)
file(GLOB CXC_HDS *.h)

# main library (prevent recompilation when building tests)
ADD_LIBRARY(cxc SHARED ${CXC_HDS} ${CXC_SRC})
SET_PROPERTY(TARGET cxc PROPERTY CXX_STANDARD 11)
