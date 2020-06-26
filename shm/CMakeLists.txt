cmake_minimum_required(VERSION 3.5)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

#set(CMAKE_CXX_COMPILER  "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_compile_options(-Wall -Wextra -pedantic -Werror  )

include(cmake/GTest.cmake)

include_directories(
        ${GTEST_INCLUDE_DIRS}
        ${GMOCK_INCLUDE_DIRS}
)



#add_executable(tests PalindromeTests.cpp)
#add_executable(tests RomanConverterTests.cpp )
#add_executable(tests Validation.cpp )
#add_executable(tests is_isomorfphic.cpp)
#add_executable(tests merge.cpp)
#add_executable(tests selection_sort.cpp) --not finished
#add_executable(tests Calculator.cpp)
add_executable(tests test.cpp Map.cpp Ship.cpp Island.cpp Cargo.cpp Player.cpp Coordinates.cpp)

target_link_libraries(tests
        gtest
        gmock
        gtest_main)


set_property(TARGET tests PROPERTY CXX_STANDARD 17)

#this is a bit of overkill, but it enables to run ctest
enable_testing()

add_test(
        NAME allTests
        COMMAND tests
)
