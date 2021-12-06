add_library (dec_6Lib OBJECT
    main.cpp
    input_6.h
)

add_executable (dec_6)
target_link_libraries (dec_6 dec_6Lib)

# add_executable(tests06 tests.cpp)
# target_link_libraries(tests06 dec_6Lib TestExe)

# catch_discover_tests(tests06)

add_custom_target(alldec_6)
add_dependencies(alldec_6 dec_6)