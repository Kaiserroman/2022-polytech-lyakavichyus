#pragma once
int partition(int arr[], int start, int end)
{

    // ������� ������� � ������ �������
    int pivot = arr[start];

    // ������� ����� ��������� ������ ��������
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // �������� ������� ������� � ������ �����
    int pivotIndex = start + count;
    swap(arr, pivotIndex, start);

    // ������������� �������� ������ ��������
    // � ����� �����, � ������ �������� � ������ �����
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr, i, j);
            i++;
            j--;
        }
    }

    return pivotIndex;
}