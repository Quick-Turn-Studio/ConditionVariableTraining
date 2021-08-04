cmake_minimum_required(VERSION 3.20)
project(ConditionVariable LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmakeUtils)

include(threadSanitizer)

add_subdirectory(thirdParty)
add_subdirectory(src)



