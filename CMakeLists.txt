cmake_minimum_required(VERSION 3.25)
project(Systems2Ex5B)

set(CMAKE_CXX_STANDARD 14)

add_executable(Systems2Ex5B Test.cpp StudentTest1.cpp sources/MagicalContainer.hpp sources/MagicalContainer.cpp Demo.cpp sources/NodeInt.hpp sources/NodeInt.cpp sources/NodeIntPtr.hpp sources/NodeIntPtr.cpp)
