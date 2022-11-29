# CMakeList.txt: проект CMake для complex; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
project(complex LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable (complex "complex.cpp" "complex.h" "doctest.h" "test_complex.cpp" )
