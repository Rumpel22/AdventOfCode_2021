add_library (dec_10Lib OBJECT
    main.cpp
    input_10.h
)

add_executable (dec_10)
target_link_libraries (dec_10 dec_10Lib)

# add_executable(tests010 tests.cpp)
# target_link_libraries(tests010 dec_10Lib TestExe)

# catch_discover_tests(tests010)

add_custom_target(alldec_10)
add_dependencies(alldec_10 dec_10)