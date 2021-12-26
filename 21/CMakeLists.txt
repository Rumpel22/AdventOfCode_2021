add_library (dec_21Lib OBJECT
    main.cpp
    input_21.h
)

add_executable (dec_21)
target_link_libraries (dec_21 dec_21Lib)

# add_executable(tests021 tests.cpp)
# target_link_libraries(tests021 dec_21Lib TestExe)

# catch_discover_tests(tests021)

add_custom_target(alldec_21)
add_dependencies(alldec_21 dec_21)