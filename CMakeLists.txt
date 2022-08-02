cmake_minimum_required(VERSION 3.23)
project(BigInteger)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BigInteger
        BigInteger.hpp
        Compare.cpp
        Conversation.cpp
        Division.cpp
        main.cpp
        Multiplication.cpp
        Pow.cpp
        Subtraction.cpp
        Sum.cpp
        UnaryOperation.cpp)
