// mateq.cpp: определяет точку входа для приложения.
//

#include "matmul.h"
#include "mateq.h"
using namespace std;

int main()
{
    while (true) {
        int r_a, c_a, r_b, c_b;

        cout << "Enter the rows and colums for the first mat." << endl;

        cin >> r_a >> c_a;

        cout << "Enter the rows and colums for the second mat." << endl;

        cin >> r_b >> c_b;

        int** a = arr_create(r_a, c_a);
        int** b = arr_create(r_b, c_b);

        cout << "Fill the first mat:" << endl;

        fill_array(a, r_a, c_a);

        cout << "Fill the second mat:" << endl;

        fill_array(b, r_b, c_b);

        bool f = mateq(a, r_a, c_a, b, r_b, c_b);

        if (f == false)
        {
            cout << "not equal" << endl << endl;
        }

        if (f == true)
        {
            cout << "Mat are equal" << endl << endl;
        }

        delete_arr(a, r_a);
        delete_arr(b, r_b);

        system("pause 0");
    }
    return 0;
}