#include <iostream>
#include <cstring>
using namespace std;

unsigned long Hash(const char* str) {
	unsigned long res = 0, g=31;
	for (int j = 0; str[j]; j++)
		res = g*res+str[j];
	return res;
}

int main() {
	const char* ex = "this";
	unsigned int c = Hash(ex);
	cout << "Hash of 'test' is:" << c << endl;
	return 0;
}
