// matmul.cpp: определяет точку входа для приложения.
//

#include "matmul.h"

int main()
{
    int r_a = 2;
    int c_a = 2;
    int** a = arr_create(r_a, c_a);
    fill_array(a, r_a, c_a);
    print_array(a, r_a, c_a);

    int r_b = 2;
    int c_b = 2;
    int** b = arr_create(r_b, c_b);
    fill_array(b, r_b, c_b);
    print_array(b, r_b, c_b);

    int r_c = r_a, c_c = c_b;
    int** c = arr_create(r_c, c_c);
    matmul(a, r_a, c_a, b, r_b, c_b, c);

    print_array(c, r_a, c_b);
    delete_arr(a, r_a);
    delete_arr(b, r_b);
    delete_arr(c, r_c);

    system("pause 0");
    return 0;
}
