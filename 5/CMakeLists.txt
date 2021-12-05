add_library (dec_5Lib OBJECT
    main.cpp
    input_5.h
)

add_executable (dec_5)
target_link_libraries (dec_5 dec_5Lib)

# add_executable(tests05 tests.cpp)
# target_link_libraries(tests05 dec_5Lib TestExe)

# catch_discover_tests(tests05)

add_custom_target(alldec_5)
add_dependencies(alldec_5 dec_5)