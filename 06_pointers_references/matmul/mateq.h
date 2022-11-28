#pragma once

#include "matmul.h"
bool mateq(int** a, int m_a, int n_a, int** b, int m_b, int n_b)
{
    bool f = true;
    if (m_a != m_b || n_a != n_b)
    {
        return f = false; //если кол-во строк и столбцов не совпадает, то матрицы не равны apriore
    }

    else
    {
        for (int i = 0; i < m_a; i++)
        {
            for (int j = 0; j < n_a; j++)
            {
                if (a[i][j] != b[i][j]) //сравниваем элементы матриц
                {
                    return f = false;
                }
            }
        }
        return f = true;
    }
}