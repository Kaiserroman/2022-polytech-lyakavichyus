// intro.cpp: определяет точку входа для приложения.
//

#include <cassert>
#include <iostream>
#include <string.h>
using namespace std;

unsigned int length(const char* str)
{
    if (str == nullptr || length(str) == 0) {
        return 0;
    }
    else {
        int size = 0;
        while (*str++) size++;
        return size;
    }
}

int convert(const char* s) {
    int p = 0;
    const char eth[] = "0123456789";
    for (int i = 0; i < strlen(s); i++) {

        for (int j = 0; j < 10; j++) {
            if (s[i] == eth[j]) {
                p *= 10;
                p += j;
            }
        }
    }
    if (s[0] == '-')
        p += (-1);
    return p;
}

const char* to_char(int N) {
    if (!N)
        return "0";
    int m = N;
    int digit = 0;
    while (m) {
        digit++;
        m /= 10;
    }
    char* arr;
    char* arr1 = new char[digit];
    arr = (char*)malloc(digit);
    int index = 0;
    while (N) {
        arr1[++index] = N % 10 + '0';
        N /= 10;
    }
    int i;
    for (i = 0; i < index; i++) {
        arr[i] = arr1[index - i];
    }
    arr[i] = '\0';
    return (const char*)arr;
}

const char* mul(const char* k, const char* n)
{
    int a = convert(k) * convert(n);
    return to_char(a);
}


int main()
{
    assert(strcmp(mul("3", "2"), "6") == 0);
    assert(strcmp(mul("12312", "0"), "0") == 0);
    assert(strcmp(mul("99", "99"), "9801") == 0);
    return 0;
}