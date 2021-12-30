add_library (dec_22Lib OBJECT
    main.cpp
    input_22.h
)

add_executable (dec_22)
target_link_libraries (dec_22 dec_22Lib)

# add_executable(tests022 tests.cpp)
# target_link_libraries(tests022 dec_22Lib TestExe)

# catch_discover_tests(tests022)

add_custom_target(alldec_22)
add_dependencies(alldec_22 dec_22)