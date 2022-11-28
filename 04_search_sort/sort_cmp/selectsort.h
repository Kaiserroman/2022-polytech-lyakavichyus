#pragma once
void selection_sort(int arr[], int size)
{
    // Проходим каждую позицию
    for (int i = 0; i < size - 1; i++)
    {
        // Ищем подходящий элемент
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        // Проверяем нужна ли перестановка
        if (min_index != i)
        {
            // вспомогательная функция
            swap(arr, i, min_index);
        }
    }
}