#include "substr.h"
#include <string>
using namespace std;

int main() {
    String str = "aboba";
    String under = "a";

    String s = "";
    int* a = s.search(str, under);
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        cout << a[i] << endl;
    }
    delete a;
    return 0;
}