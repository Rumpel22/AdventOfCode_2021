add_library (dec_20Lib OBJECT
    main.cpp
    input_20.h
)

add_executable (dec_20)
target_link_libraries (dec_20 dec_20Lib)

# add_executable(tests020 tests.cpp)
# target_link_libraries(tests020 dec_20Lib TestExe)

# catch_discover_tests(tests020)

add_custom_target(alldec_20)
add_dependencies(alldec_20 dec_20)