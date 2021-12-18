add_library (dec_17Lib OBJECT
    main.cpp
    input_17.h
)

add_executable (dec_17)
target_link_libraries (dec_17 dec_17Lib)

# add_executable(tests017 tests.cpp)
# target_link_libraries(tests017 dec_17Lib TestExe)

# catch_discover_tests(tests017)

add_custom_target(alldec_17)
add_dependencies(alldec_17 dec_17)