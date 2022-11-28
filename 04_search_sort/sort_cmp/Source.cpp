#include<iostream>
#include <ctime> 
#include"swap.h"
#include"partition.h"
#include"fillrandom.h"
#include"selectsort.h"
#include"quicksort.h"
using namespace std;

int main() {
	long double cstart, cend, resss, resqs;
	while(true){
		//типо динамический массив
		int n = 0;
		cout << "Size:" << endl;
		cin >> n; 
		int* arr = new int[n];
		
		//заполняе м рандомно
		for (int i = 0; i <= n; i++) {
			fill_array_random(arr, n);
		}

		//считаем время
		cstart = clock();
		selection_sort(arr, n);
		cend = clock();
		resss = cend - cstart;

		//заполняе м рандомно
		for (int i = 0; i <= n; i++) {
			fill_array_random(arr, n);
		}

		//считаем время
		cstart = clock();
		quick_sort (arr, 0, n-1);
		cend = clock();
		resqs = cend - cstart;

		//выводим результаты
		cout << "1e" << n << " " << resss << "(ss), " << resqs << "(qs)" << endl;

		delete[] arr;
	}
	return 0;
 }