// main.cpp.cpp: определяет точку входа для приложения.
//

#include "String.h"
#include <iostream>

int main() {
	String a = "help";
	String b = a + " pls";
	std::cout << b << '\n' << b.get_length();
	system("pause 0");
	return 0;
}