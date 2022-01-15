add_library (dec_25Lib OBJECT
    main.cpp
    input_25.h
)

add_executable (dec_25)
target_link_libraries (dec_25 dec_25Lib)

# add_executable(tests025 tests.cpp)
# target_link_libraries(tests025 dec_25Lib TestExe)

# catch_discover_tests(tests025)

add_custom_target(alldec_25)
add_dependencies(alldec_25 dec_25)