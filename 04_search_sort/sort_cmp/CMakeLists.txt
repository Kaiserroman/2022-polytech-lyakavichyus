# CMakeList.txt: проект CMake для sort_cmp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (sort_cmp "sort_cmp.cpp" "fillrandom.h" "partition.h" "quicksort.h" "selectsort.h" "swap.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
