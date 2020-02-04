

# better way ?
INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(..)

file(GLOB CXS_SRC *.c)
file(GLOB CXS_HDS *.h)

# main library (prevent recompilation when building tests)
ADD_LIBRARY(cxs SHARED ${CXS_HDS} ${CXS_SRC})
SET_PROPERTY(TARGET cxs PROPERTY CXX_STANDARD 11)
