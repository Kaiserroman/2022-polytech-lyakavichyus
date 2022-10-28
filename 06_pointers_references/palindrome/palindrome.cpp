// intro.cpp: определяет точку входа для приложения.
//

#include <cassert>
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

bool palcheck(const char* str) {
    if (str == nullptr) {
        return false;
    }
    else {
        if (length(str) == 1)
            return true;
        else {
            if (length(str) % 2 == 0) {
                int n = length(str);
                for (int i = 0; i < (n / 2); i++) {
                    if (str[n / 2 - 1 - i] == str[n / 2 + i]) {
                        continue;
                    }
                    else {
                        return false;
                    }
                }
                return true;
            }
            else {
                int n = length(str);
                for (int i = 0; i < (n / 2); i++) {
                    if (str[n / 2 - i] == str[n / 2 + 1]) {
                        continue;
                    }
                    else {
                        return false;
                    }
                }
                return true;
            }
        }
    }

}

int main()
{
    assert(palcheck("a") == true);
    assert(palcheck("ab") == false);
    assert(palcheck("aa") == true);
    assert(palcheck("") == false);
    assert(palcheck("abcdcba") == true);
    assert(palcheck("abcddcba") == true);
    assert(palcheck(nullptr) == false);
    return 0;
}