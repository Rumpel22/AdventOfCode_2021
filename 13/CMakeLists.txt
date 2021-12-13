add_library (dec_13Lib OBJECT
    main.cpp
    input_13.h
)

add_executable (dec_13)
target_link_libraries (dec_13 dec_13Lib)

# add_executable(tests013 tests.cpp)
# target_link_libraries(tests013 dec_13Lib TestExe)

# catch_discover_tests(tests013)

add_custom_target(alldec_13)
add_dependencies(alldec_13 dec_13)