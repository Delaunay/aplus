

# better way ?
INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(..)

file(GLOB ESF_SRC *.c)
file(GLOB ESF_HDS *.h)

# main library (prevent recompilation when building tests)
ADD_LIBRARY(esf SHARED ${ESF_HDS} ${ESF_SRC})
SET_PROPERTY(TARGET esf PROPERTY CXX_STANDARD 11)
