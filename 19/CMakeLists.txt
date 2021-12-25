add_library (dec_19Lib OBJECT
    main.cpp
    input_19.h
)

add_executable (dec_19)
target_link_libraries (dec_19 dec_19Lib)

# add_executable(tests019 tests.cpp)
# target_link_libraries(tests019 dec_19Lib TestExe)

# catch_discover_tests(tests019)

add_custom_target(alldec_19)
add_dependencies(alldec_19 dec_19)