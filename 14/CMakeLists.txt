add_library (dec_14Lib OBJECT
    main.cpp
    input_14.h
)

add_executable (dec_14)
target_link_libraries (dec_14 dec_14Lib)

# add_executable(tests014 tests.cpp)
# target_link_libraries(tests014 dec_14Lib TestExe)

# catch_discover_tests(tests014)

add_custom_target(alldec_14)
add_dependencies(alldec_14 dec_14)