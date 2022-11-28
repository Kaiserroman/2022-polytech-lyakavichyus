#pragma once
void swap(int arr[], int idx_a, int idx_b)
{
    int temp = arr[idx_a]; // временная переменная
    arr[idx_a] = arr[idx_b];
    arr[idx_b] = temp;
}