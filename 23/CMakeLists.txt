add_library (dec_23Lib OBJECT
    main.cpp
    input_23.h
)

add_executable (dec_23)
target_link_libraries (dec_23 dec_23Lib)

# add_executable(tests023 tests.cpp)
# target_link_libraries(tests023 dec_23Lib TestExe)

# catch_discover_tests(tests023)

add_custom_target(alldec_23)
add_dependencies(alldec_23 dec_23)