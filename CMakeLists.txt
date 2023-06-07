cmake_minimum_required(VERSION 3.25)
project(Systems2Ex5B)

set(CMAKE_CXX_STANDARD 14)

add_executable(Systems2Ex5B Test.cpp StudentTest1.cpp sources/MagicalContainer.hpp sources/MagicalContainer.cpp Demo.cpp sources/LinkedList.hpp sources/AscendingIterator.cpp sources/PrimeIterator.cpp sources/SideCrossIterator.cpp sources/LinkedList.cpp)
