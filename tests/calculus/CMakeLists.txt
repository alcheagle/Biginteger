cmake_minimum_required (VERSION 2.8)

project(construction_test)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

add_executable(sum_test ${CMAKE_CURRENT_LIST_DIR}/sum.cpp)
#add_executable(run_test4 ${CMAKE_CURRENT_LIST_DIR}/construction4.cpp)

target_link_libraries(
    sum_test
    Bigint
)

#target_link_libraries(
#    run_test4
#    Bigint
#)


add_test(NAME "${subdir}.sum"
        WORKING_DIRECTORY ${TESTS_DIR}/${subdir}
        COMMAND ${CMAKE_CURRENT_LIST_DIR}/bin/sum_test)

#add_test(NAME "${subdir}.4"
#        WORKING_DIRECTORY ${TESTS_DIR}/${subdir}
#        COMMAND ${CMAKE_CURRENT_LIST_DIR}/bin/run_test4)