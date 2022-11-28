// matmul.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
using namespace std;

int** arr_create(int rows, int cols) // создаем динамический двумерный массив(тип матрица)
{
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    return arr;
}

void fill_array(int** arr, int rows, int cols) // заполняем наш массив(тип матрицу)
{
    for (int i = 0; i < rows; i++)
    {
        cout << "row: " << i + 1 << endl;

        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl;
}

void print_array(int** arr, int rows, int cols) // выводим наш массив (тип матрицу) на экран консоли
{
    for (int i = 0; i <rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl << endl;
    }
}
void matmul(int** a, int r_a, int c_a, int** b, int r_b, int c_b, int** c) // перемножаем два массива (тип матрицы)
{
    for (int i = 0; i < r_a; i++)
    {
        for (int j = 0; j < c_b; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < r_b; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void delete_arr(int** a, int m) //очищаем вручную оперативную память
{
    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
    }
}

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
