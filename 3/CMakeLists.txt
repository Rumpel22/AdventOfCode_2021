add_library (dec_3Lib OBJECT
    main.cpp
    input_3.h
)

add_executable (dec_3)
target_link_libraries (dec_3 dec_3Lib)

# add_executable(tests03 tests.cpp)
# target_link_libraries(tests03 dec_3Lib TestExe)

# catch_discover_tests(tests03)

add_custom_target(alldec_3)
add_dependencies(alldec_3 dec_3)