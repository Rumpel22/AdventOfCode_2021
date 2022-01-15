add_library (dec_24Lib OBJECT
    main.cpp
    input_24.h
)

add_executable (dec_24)
target_link_libraries (dec_24 dec_24Lib)

# add_executable(tests024 tests.cpp)
# target_link_libraries(tests024 dec_24Lib TestExe)

# catch_discover_tests(tests024)

add_custom_target(alldec_24)
add_dependencies(alldec_24 dec_24)