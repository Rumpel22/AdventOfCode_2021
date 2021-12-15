add_library (dec_15Lib OBJECT
    main.cpp
    input_15.h
)

add_executable (dec_15)
target_link_libraries (dec_15 dec_15Lib)

# add_executable(tests015 tests.cpp)
# target_link_libraries(tests015 dec_15Lib TestExe)

# catch_discover_tests(tests015)

add_custom_target(alldec_15)
add_dependencies(alldec_15 dec_15)