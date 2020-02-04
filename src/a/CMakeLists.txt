

# better way ?
INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(..)

file(GLOB A_SRC *.c)
file(GLOB A_HDS *.h)

# main library (prevent recompilation when building tests)
ADD_LIBRARY(a SHARED ${A_HDS} ${A_SRC})
SET_PROPERTY(TARGET a PROPERTY CXX_STANDARD 11)
