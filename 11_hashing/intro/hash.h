#pragma once
unsigned long Hash(const char* str) {
	unsigned long res = 0, g = 31;
	for (int j = 0; str[j]; j++)
		res = g * res + str[j];
	return res;
}