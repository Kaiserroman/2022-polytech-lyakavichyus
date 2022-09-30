#include<iostream>

using namespace std;

int main() {
	const int n = 10;
	int arin[n]={1, 1, 3, 7, 12, 57, 7, 128, 2000, 7}, arout[n], count = 0;


	
	for (int i = 0, j=0; i <= (n - 1); i++) {
		if (arin[i] == 7) {
			arout[j] = i;
			j++;
			count++;
		}
	}

	for (int i = 0; i < count; i++) {
		cout << arout[i]<<endl;
	}
	return 0;
}

