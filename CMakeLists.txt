cmake_minimum_required(VERSION 3.2)

project(timus_08 VERSION 1.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(timus_1196 ./1196/main.cpp )
add_executable(timus_1496 ./1496/main.cpp )
add_executable(timus_1545 ./1545/main.cpp )
add_executable(timus_1837 ./1837/main.cpp )

add_executable(test_1196 ./1196/test.cpp)
add_executable(test_1496 ./1496/test.cpp)
add_executable(test_1545 ./1545/test.cpp)
add_executable(test_1837 ./1837/test.cpp)

set_target_properties(test_1196 test_1496 test_1545 test_1837 PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(test_1196 
  ${Boost_LIBRARIES}
)
target_link_libraries(test_1496 
  ${Boost_LIBRARIES}
)
target_link_libraries(test_1545 
  ${Boost_LIBRARIES}
)
target_link_libraries(test_1837 
  ${Boost_LIBRARIES}
)

enable_testing()

add_test(test_1196    test_1196 -t test_suite_main)
add_test(test_1496    test_1496 -t test_suite_main)
add_test(test_1545    test_1545 -t test_suite_main)
add_test(test_1837    test_1837 -t test_suite_main)