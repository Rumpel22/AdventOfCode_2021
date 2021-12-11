add_library (dec_7Lib OBJECT
    main.cpp
    input_7.h
)

add_executable (dec_7)
target_link_libraries (dec_7 dec_7Lib)

# add_executable(tests07 tests.cpp)
# target_link_libraries(tests07 dec_7Lib TestExe)

# catch_discover_tests(tests07)

add_custom_target(alldec_7)
add_dependencies(alldec_7 dec_7)