#pragma once
void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    // Разбиение массива
    int p = partition(arr, start, end);

    // Сортировка левой части
    quick_sort(arr, start, p - 1);
    // Сортировка правой части
    quick_sort(arr, p + 1, end);
}