add_library (dec_11Lib OBJECT
    main.cpp
    input_11.h
    field.h
)

add_executable (dec_11)
target_link_libraries (dec_11 dec_11Lib)

# add_executable(tests011 tests.cpp)
# target_link_libraries(tests011 dec_11Lib TestExe)

# catch_discover_tests(tests011)

add_custom_target(alldec_11)
add_dependencies(alldec_11 dec_11)