set(LIB_NAME ProducerConsumer)

project(${LIB_NAME})

aux_source_directory(. SRC_FILES)

add_library(${LIB_NAME} STATIC ${SRC_FILES})

target_include_directories(${LIB_NAME} INTERFACE .)

target_link_libraries(${LIB_NAME} PUBLIC Stacks)

add_subdirectory(tests)
