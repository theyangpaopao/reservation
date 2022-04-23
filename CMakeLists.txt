cmake_minimum_required(VERSION 3.21)
project(reservation)

set(CMAKE_CXX_STANDARD 14)

add_executable(reservation main.cpp identity.h student.cpp student.h teacher.cpp teacher.h manager.cpp manager.h globalFile.h loginin.cpp computerroom.h orderfile.cpp orderfile.h)
