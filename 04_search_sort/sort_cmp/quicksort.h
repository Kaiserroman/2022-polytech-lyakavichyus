#pragma once
void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    // ��������� �������
    int p = partition(arr, start, end);

    // ���������� ����� �����
    quick_sort(arr, start, p - 1);
    // ���������� ������ �����
    quick_sort(arr, p + 1, end);
}