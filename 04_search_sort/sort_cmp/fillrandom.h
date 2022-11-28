#pragma once
#include <stdlib.h>
#include <time.h>

void fill_array_random(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand();
    }
}