#include <iostream>
using namespace std;

struct Node //узел
{
    int data; //значение
    Node* left; //указатель налево  
    Node* right; //указатель направо
};

//прямой обход  в глубину - узел/левый/правый
void direct_bypass(Node* a) //в аргументы забиваем указатель на узел
{
    if (!a) { return; } //елси 1 элемент - возвращаем

    else
    {
        cout << a->data << ", "; //выводим значение узла
        direct_bypass(a->left); //идём слева
        direct_bypass(a->right); //идём справа
    }
}

//симметричный обход в глубину - левый/узел/справа
void symmetric(Node* a) //в аргументы забиваем указатель на узел
{
    if (!a) { return; } //защита от дурочка

    else
    {
        symmetric(a->left); //идём слева
        cout << a->data << ", "; //выводим узел
        symmetric(a->right); //идём справа
    }
}

//обратный обход в глубину - левый/правый/узел
void in_order(Node* a) //в аргументы забиваем указатель на узел
{
    if (!a) { return; } //защита от дурочка

    else
    {
        in_order(a->left); //идём слева
        in_order(a->right); //идём справа
        cout << a->data << ", "; //выводим узел
    }
}

int main()
{
    //создаём дерево а-б-с
    auto* a = new Node{ 2, nullptr, nullptr };
    auto* b = new Node{ 1, nullptr, nullptr };
    auto* c = new Node{ 3, nullptr, nullptr };
    a->left = b;
    a->right = c;

    cout << "direct bypass" << endl; //должно вывести: a, b, c
    direct_bypass(a);
    cout << endl << endl;
    cout << "symmetric bypass" << endl; //должно вывести b, a, c
    symmetric(a);
    cout << endl << endl;
    cout << "in-order bypass" << endl; //должно вывести b, c, a
    in_order(a);
    cout << endl << endl;

    //чистим память 
    delete c;
    delete b;
    delete a;

    system("pause 0");
    return 0;
}
