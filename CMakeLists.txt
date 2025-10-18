cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled
        main.cpp
        user.cpp
        student.cpp
        professor.cpp
        librarian.cpp
        books.cpp
        utils.cpp)
