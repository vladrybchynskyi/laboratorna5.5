cmake_minimum_required(VERSION 3.30.5)

set(This labor5_5test)

set(Sources
   labor5_5test.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    laborw5_5
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
