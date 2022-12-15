#include <iostream>
using namespace std;

struct Node //узел
{
    int data;
    Node* left;
    Node* right;
};

//прямой обход  в глубину
void direct_bypass(Node* a)
{
    if (!a) { return; }

    else
    {
        cout << a->data << ", ";
        direct_bypass(a->left);
        direct_bypass(a->right);
    }
}

//симметричный обход в глубину
void symmetric(Node* a)
{
    if (!a) { return; }

    else
    {
        symmetric(a->left);
        cout << a->data << ", ";
        symmetric(a->right);
    }
}

//обратный обход в глубину
void in_order(Node* a)
{
    if (!a) { return; }

    else
    {
        in_order(a->left);
        in_order(a->right);
        cout << a->data << ", ";
    }
}

int main()
{
    auto* root = new Node{ 6, nullptr, nullptr };
    auto* a = new Node{ 5, nullptr, nullptr };
    auto* b = new Node{ 4, nullptr, nullptr };
    auto* c = new Node{ 3, nullptr, nullptr };
    auto* d = new Node{ 2, nullptr, nullptr };
    auto* e = new Node{ 7, nullptr, nullptr };

    root->left = a;
    a->left = b;
    b->left = c;
    c->left = d;
    root->right = e;

    cout << "direct bypass" << endl;
    direct_bypass(root);
    cout << endl << endl;
    cout << "symmetric bypass" << endl;
    symmetric(root);
    cout << endl << endl;
    cout << "in-order bypass" << endl;
    in_order(root);
    cout << endl << endl;

    delete root;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;

    system("pause 0");
    return 0;
}