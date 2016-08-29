cmake_minimum_required (VERSION 2.8)

project(construction_test)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

add_executable(comparison ${CMAKE_CURRENT_LIST_DIR}/comparison.cpp)

target_link_libraries(
    comparison
    Bigint
)

add_test(NAME "${subdir}"
        WORKING_DIRECTORY ${TESTS_DIR}/${subdir}
        COMMAND ${CMAKE_CURRENT_LIST_DIR}/bin/comparison)