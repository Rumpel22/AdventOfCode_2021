add_library (dec_8Lib OBJECT
    main.cpp
    input_8.h
)

add_executable (dec_8)
target_link_libraries (dec_8 dec_8Lib)

# add_executable(tests08 tests.cpp)
# target_link_libraries(tests08 dec_8Lib TestExe)

# catch_discover_tests(tests08)

add_custom_target(alldec_8)
add_dependencies(alldec_8 dec_8)