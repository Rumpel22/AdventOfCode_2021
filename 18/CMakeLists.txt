add_library (dec_18Lib OBJECT
    main.cpp
    input_18.h
)

add_executable (dec_18)
target_link_libraries (dec_18 dec_18Lib)

# add_executable(tests018 tests.cpp)
# target_link_libraries(tests018 dec_18Lib TestExe)

# catch_discover_tests(tests018)

add_custom_target(alldec_18)
add_dependencies(alldec_18 dec_18)