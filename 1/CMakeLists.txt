add_library (dec_1Lib OBJECT
    main.cpp
    input_1.h
)

add_executable (dec_1)
target_link_libraries (dec_1 dec_1Lib)

# add_executable(tests01 tests.cpp)
# target_link_libraries(tests01 dec_1Lib TestExe)

# catch_discover_tests(tests01)

add_custom_target(alldec_1)
add_dependencies(alldec_1 dec_1)