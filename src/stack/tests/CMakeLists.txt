set(TEST_NAME StackTests)

aux_source_directory(. TEST_FILES)

add_executable(${TEST_NAME} ${TEST_FILES})

target_link_libraries(${TEST_NAME} PRIVATE gmock_main)
target_link_libraries(${TEST_NAME} PRIVATE Stacks)