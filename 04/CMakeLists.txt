add_library (dec_4Lib OBJECT
    main.cpp
    input_4.h
)

add_executable (dec_4)
target_link_libraries (dec_4 dec_4Lib)

# add_executable(tests04 tests.cpp)
# target_link_libraries(tests04 dec_4Lib TestExe)

# catch_discover_tests(tests04)

add_custom_target(alldec_4)
add_dependencies(alldec_4 dec_4)