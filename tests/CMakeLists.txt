cmake_minimum_required (VERSION 2.8)

MACRO(SUBDIRLIST result curdir) #this macro finds every subdirectory with a CMakeLists.txt file inside
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(dirlist "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY ${curdir}/${child})
            IF(EXISTS ${curdir}/${child}/CMakeLists.txt)
                LIST(APPEND dirlist ${child})
            ENDIf()
        ENDIF()
    ENDFOREACH()
    SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(SUBDIRS ${TESTS_DIR})

set(AKS_DIR ${CMAKE_CURRENT_LIST_DIR}/../)

FOREACH(subdir ${SUBDIRS})
    message("Adding test: " ${TESTS_DIR}/${subdir})
    add_subdirectory(${TESTS_DIR}/${subdir})

    add_test(NAME ${subdir}
        WORKING_DIRECTORY ${TESTS_DIR}/${subdir}
        COMMAND ${TESTS_DIR}/${subdir}/bin/run_test)
ENDFOREACH()
