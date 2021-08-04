set(APP_NAME BankingApp)

project(${APP_NAME})

aux_source_directory(. SRC_FILES)

add_executable(${APP_NAME} ${SRC_FILES})

target_link_libraries(${APP_NAME} PUBLIC Stacks)

if (CMAKE_CXX_COMPILER_ID MATCHES GNU)
    target_link_libraries(${APP_NAME} PUBLIC pthread)
endif()