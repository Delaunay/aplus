
add_test(NAME aplus_fsftest
    WORKING_DIRECTORY .
    COMMAND ./bin/aplus ../tests/fsftest.+)

add_test(NAME aplus_bigs
    WORKING_DIRECTORY .
    COMMAND  ./bin/aplus ../lib/acore/bigs.+)

add_test(NAME aplus_dio
    WORKING_DIRECTORY .
    COMMAND  ./bin/aplus ../lib/acore/dio.+)

add_test(NAME aplus_disp
    WORKING_DIRECTORY .
    COMMAND  ./bin/aplus ../lib/acore/disp.+)

add_test(NAME aplus_idap
    WORKING_DIRECTORY .
    COMMAND  ./bin/aplus ../lib/acore/idap.+)

add_test(NAME aplus_t
    WORKING_DIRECTORY .
    COMMAND  ./bin/aplus ../lib/acore/t.+)

setup_target_for_coverage_gcovr_html(
    NAME aplus_coverage
    EXECUTABLE ctest -j 4)
