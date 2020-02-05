# better way ?
INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(..)

file(GLOB APLUS_SRC *.c *.cpp)
file(GLOB APLUS_HDS *.h)

# main library (prevent recompilation when building tests)
ADD_EXECUTABLE(aplus ${APLUS_SRC} ${APLUS_HDS})

TARGET_LINK_LIBRARIES(aplus a dap cxb cxc cxs cxsys esf)
TARGET_LINK_LIBRARIES(aplus pthread dl nsl m)
# pthread: multithreading
# dl     : loading shared libraries
# nsl    : Network Switch Layer

SET_PROPERTY(TARGET aplus PROPERTY CXX_STANDARD 11)
