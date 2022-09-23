#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double a = 0, b = 0;
    char s;
    while (true)
    {
        cout << "Enter two numbers and desired operation between them :" << endl;
        cin >> a >> s >> b;
        switch (s)
        {
        case '+':
            cout << "Answer:" << a + b << endl;
            break;
        case '-':
            cout << "Answer:" << a - b << endl;
            break;
        case '*':
            cout << "Answer:" << a * b << endl;
            break;
        case '/':
            if (b == 0) {
                cout << "error" << endl;
                break;
            }
            else {
                cout << "Answer:" << pow(a, b) << endl;
                break;
            }
        case '^':
            cout << "Answer:" << pow(a,b) << endl;
            break;
        default:
            return 0;
            break;
        }
    }
}

