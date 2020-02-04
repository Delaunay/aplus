

# better way ?
INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(..)

file(GLOB CXB_SRC *.c)
file(GLOB CXB_HDS *.h)

# main library (prevent recompilation when building tests)
ADD_LIBRARY(cxb SHARED ${CXB_HDS} ${CXB_SRC})
SET_PROPERTY(TARGET cxb PROPERTY CXX_STANDARD 11)
