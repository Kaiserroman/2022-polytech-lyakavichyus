# CMakeList.txt: проект CMake для student; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (student "test_students.cpp" "student.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
