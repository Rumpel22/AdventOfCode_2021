add_library (dec_2Lib OBJECT
    main.cpp
    input_2.h
)

add_executable (dec_2)
target_link_libraries (dec_2 dec_2Lib)

# add_executable(tests02 tests.cpp)
# target_link_libraries(tests02 dec_2Lib TestExe)

# catch_discover_tests(tests02)

add_custom_target(alldec_2)
add_dependencies(alldec_2 dec_2)