cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME "balsam")
set(PROJECT_PATH      ${CMAKE_SOURCE_DIR} )
set(PROJECT_OUT_PATH  ${CMAKE_BINARY_DIR} )
set(PROJECT_INCLUDES  "include" )
set(PROJECT_LIBRARIES  "" )
set(CMAKE_C_STANDARD 11)

#SET(GCC_COVERAGE_COMPILE_FLAGS "-O2")
#SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

FILE( GLOB_RECURSE PROJECT_SOURCES src/*.c )
FILE( GLOB_RECURSE PROJECT_HEADERS include/${PROJECT_NAME}/*.h )

project(${PROJECT_NAME})

include_directories(${PROJECT_INCLUDES})

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

find_library(RABBITMQ_LIBRARY NAMES librabbitmq.a)

if (NOT RABBITMQ_LIBRARY)
    message(FATAL_ERROR "Package rabbitmq required, but not found")
else()
    message("rabbitmq path: ${RABBITMQ_LIBRARY}")
endif(NOT RABBITMQ_LIBRARY)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} ${RABBITMQ_LIBRARY})