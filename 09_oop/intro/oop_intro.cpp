// oop_intro.cpp: определяет точку входа для приложения.
//

#include "oop_intro.h"

using namespace std;

struct Person {
    Person() { 
        std::cout << "Person::ctor" << std::endl; } //конструктор
    ~Person() { std::cout << "Person::dtor" << std::endl; } //деструктор
    std::string name{};
};

struct Student : virtual public Person {
    Student() { std::cout << "Student::ctor" << std::endl; } //конструктор
    ~Student() { std::cout << "Student::dtor" << std::endl; } //деструктор
    int score{};
};

struct Teacher : virtual public Person {
    Teacher() { std::cout << "Teacher::ctor" << std::endl; } //конструктор
    ~Teacher() { std::cout << "Teacher::dtor" << std::endl; } //деструктор
};

struct TA : Teacher, Student {};

int main()
{
    TA ta;
    ta.score = 5.0;
    ta.name = "Da Sha";

    return 0;
}

