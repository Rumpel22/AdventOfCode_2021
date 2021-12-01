add_subdirectory(../libs/Catch2 ${CMAKE_BINARY_DIR}/catch2)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../libs/Catch2/contrib)
include(Catch)

add_library(TestExe testExe.cpp)
target_link_libraries(TestExe PUBLIC Catch2::Catch2)

enable_testing()