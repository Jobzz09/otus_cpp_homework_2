cmake_minimum_required(VERSION 3.0.0)
set(CXX_STANDARD 17)
project(new_project VERSION 0.1.0)

set (project_include ./include)

include(CTest)
enable_testing()

file(GLOB TARGET_SRC "./src/*.cpp" )

add_executable(main ${TARGET_SRC})

target_include_directories(main
PUBLIC "${CMAKE_SOURCE_DIR}/include")


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
