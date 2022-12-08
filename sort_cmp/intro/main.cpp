#include <iostream>
#include <cstring>
using namespace std;

unsigned int Hash(string& S) {
	unsigned res = 0, g = 31;
	for (unsigned int i : S) {
		res = g * res + S[i];
	}
	return res;
}

int main() {
	string ex = "test";
	unsigned int c = Hash(ex);
	cout << "Hash of 'test' is:" << c << endl;
	return 0;
}

//this = 3836621
//tsih = 4292465285
//isht = 2716083
//hist = 4292803794
//shit = 4293520473
// !compile online!