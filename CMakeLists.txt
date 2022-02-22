cmake_minimum_required(VERSION 3.0.0)
set(CXX_STANDARD 17)
project(new_project VERSION 0.1.0)

set (project_include ./include)

option(WITH_GOOGLE_TEST "Whether to build gtest" OFF)

include(CTest)
enable_testing()

file(GLOB TARGET_SRC "./src/*.cpp" )

add_executable(main ${TARGET_SRC})

target_include_directories(main
PUBLIC "${CMAKE_SOURCE_DIR}/include")

if (WITH_GOOGLE_TEST)
    find_package(PkgConfig)
        
    pkg_check_modules(GTEST REQUIRED gtest>=1.5.0)

    include_directories(
        ${GTEST_INCLUDE_DIRS}
    )

    add_executable(google_test_1 "./test/gtest.cpp" "./test/main.cpp")

    target_include_directories(google_test_1
        PUBLIC "${CMAKE_SOURCE_DIR}/include"
        PUBLIC ${PROJECT_BINARY_DIR})

    target_link_libraries(google_test_1
    PRIVATE ${GTEST_LIBRARIES})

    target_link_directories(google_test_1
    PRIVATE ${PROJECT_BINARY_DIR})

    add_test(google_test_1 google_test_1)
    enable_testing()
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
