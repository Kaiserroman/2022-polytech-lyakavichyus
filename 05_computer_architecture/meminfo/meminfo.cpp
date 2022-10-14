// meminfo.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include <fstream>
#include <cmath>//для функции округления
using namespace std;

void show_meminfo() //вводим функцию
{
    char parameter[20];
    int value;
    char unit[3];//^^оставили с макет в гите
    int total, free, avail; //всего свободно занято

    ifstream in("/proc/meminfo", ios_base::in); //читаем файл с инфой о памяти
    if (in.is_open()) {
        in >> parameter >> total >> unit;//забиваем сколько всего памяти
        in >> parameter >> free >> unit;//забиваем сколько свободно памяти
        in >> parameter >> avail >> unit;//забиваем сколько занято памяти, строчки идут по порядку в этом файле
    }
    else {
        exit(1);//не моэем найти файл - возвращаем 1
    }

    float percent = (total - avail) / static_cast<float>(total) * 100;//вводим процент, чтобы посчитать, сколько надо палок
    int bars_count = round(percent / 10); //округляем и делим на 10, чтоб работать в "в диапозоне 10 палок"

    for (int i = 0; i != bars_count; ++i)//выводим палки в диапозоне до 10
        cout << "|";
    for (int i = 0; i != 10 - bars_count; ++i)//остальное точки
        cout << ".";
    cout << " " << static_cast<int>(percent) << "%" << endl;//выводим сам процент и знак %
}

int main()
{
    show_meminfo(); //вызываем функцию
    return 0;
}