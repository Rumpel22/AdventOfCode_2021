add_library (dec_12Lib OBJECT
    main.cpp
    input_12.h
)

add_executable (dec_12)
target_link_libraries (dec_12 dec_12Lib)

# add_executable(tests012 tests.cpp)
# target_link_libraries(tests012 dec_12Lib TestExe)

# catch_discover_tests(tests012)

add_custom_target(alldec_12)
add_dependencies(alldec_12 dec_12)