#include<iostream>
using namespace std;

int main() {
	const int n = 10;
	int arr[n]={1, 1, 3, 8, 12, 57, 7, 128, 2000, 14}, temp, l=arr[0], r=arr[n-1], x = 7, mid;

	//Типо сортировка

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	 
	//Бинарим

	int j = n-1, i = 0;
	while (arr[j] >= arr[i]) {
		mid = ((j + 1) + i) / 2;
		if (arr[mid] == x)
			cout << "ANSWER:" << mid << endl;
		if (arr[mid] > x)
			j = mid - 1;
		else
			i = mid + 1;
	}
	return 0;
}


