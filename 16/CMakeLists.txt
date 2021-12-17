add_library (dec_16Lib OBJECT
    main.cpp
    input_16.h
)

add_executable (dec_16)
target_link_libraries (dec_16 dec_16Lib)

# add_executable(tests016 tests.cpp)
# target_link_libraries(tests016 dec_16Lib TestExe)

# catch_discover_tests(tests016)

add_custom_target(alldec_16)
add_dependencies(alldec_16 dec_16)