cmake_minimum_required (VERSION 2.8)

project(construction_test)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

add_executable(run_test1 ${CMAKE_CURRENT_LIST_DIR}/construction1.cpp)
add_executable(run_test2 ${CMAKE_CURRENT_LIST_DIR}/construction2.cpp)
add_executable(run_test3 ${CMAKE_CURRENT_LIST_DIR}/construction3.cpp)
#add_executable(run_test4 ${CMAKE_CURRENT_LIST_DIR}/construction4.cpp)

target_link_libraries(
    run_test1
    Bigint
)

target_link_libraries(
    run_test2
    Bigint
)

target_link_libraries(
    run_test3
    Bigint
)

#target_link_libraries(
#    run_test4
#    Bigint
#)


add_test(NAME "${subdir}.1"
        WORKING_DIRECTORY ${TESTS_DIR}/${subdir}
        COMMAND ${CMAKE_CURRENT_LIST_DIR}/bin/run_test1)

add_test(NAME "${subdir}.2"
        WORKING_DIRECTORY ${TESTS_DIR}/${subdir}
        COMMAND ${CMAKE_CURRENT_LIST_DIR}/bin/run_test2)

add_test(NAME "${subdir}.3"
        WORKING_DIRECTORY ${TESTS_DIR}/${subdir}
        COMMAND ${CMAKE_CURRENT_LIST_DIR}/bin/run_test3)

#add_test(NAME "${subdir}.4"
#        WORKING_DIRECTORY ${TESTS_DIR}/${subdir}
#        COMMAND ${CMAKE_CURRENT_LIST_DIR}/bin/run_test4)