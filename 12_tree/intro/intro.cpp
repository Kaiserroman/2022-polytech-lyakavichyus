#include <iostream>
using namespace std;

struct Node //����
{
    int data; //��������
    Node* left; //��������� ������  
    Node* right; //��������� �������
};

//������ �����  � ������� - ����/�����/������
void direct_bypass(Node* a) //� ��������� �������� ��������� �� ����
{
    if (!a) { return; } //���� 1 ������� - ����������

    else
    {
        cout << a->data << ", "; //������� �������� ����
        direct_bypass(a->left); //��� �����
        direct_bypass(a->right); //��� ������
    }
}

//������������ ����� � ������� - �����/����/������
void symmetric(Node* a) //� ��������� �������� ��������� �� ����
{
    if (!a) { return; } //������ �� �������

    else
    {
        symmetric(a->left); //��� �����
        cout << a->data << ", "; //������� ����
        symmetric(a->right); //��� ������
    }
}

//�������� ����� � ������� - �����/������/����
void in_order(Node* a) //� ��������� �������� ��������� �� ����
{
    if (!a) { return; } //������ �� �������

    else
    {
        in_order(a->left); //��� �����
        in_order(a->right); //��� ������
        cout << a->data << ", "; //������� ����
    }
}

int main()
{
    //������ ������ �-�-�
    auto* a = new Node{ 2, nullptr, nullptr };
    auto* b = new Node{ 1, nullptr, nullptr };
    auto* c = new Node{ 3, nullptr, nullptr };
    a->left = b;
    a->right = c;

    cout << "direct bypass" << endl; //������ �������: a, b, c
    direct_bypass(a);
    cout << endl << endl;
    cout << "symmetric bypass" << endl; //������ ������� b, a, c
    symmetric(a);
    cout << endl << endl;
    cout << "in-order bypass" << endl; //������ ������� b, c, a
    in_order(a);
    cout << endl << endl;

    //������ ������ 
    delete c;
    delete b;
    delete a;

    system("pause 0");
    return 0;
}
