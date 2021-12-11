add_library (dec_9Lib OBJECT
    main.cpp
    input_9.h
)

add_executable (dec_9)
target_link_libraries (dec_9 dec_9Lib)

# add_executable(tests09 tests.cpp)
# target_link_libraries(tests09 dec_9Lib TestExe)

# catch_discover_tests(tests09)

add_custom_target(alldec_9)
add_dependencies(alldec_9 dec_9)