In order to add a test you have to create a subdir under here and create a CMakeList.txt which has to contain this code

```target_link_libraries(
    EXECUTABLE
    Bigint
)

add_test(NAME ${subdir}
        WORKING_DIRECTORY ${TESTS_DIR}/${subdir}
    COMMAND COMMAND)
```
