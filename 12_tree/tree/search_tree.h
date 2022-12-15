#include<iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct Tree
{
    int data;
    Tree* left;
    Tree* right;
    Tree* search(Tree* root, int x);
    Tree* insert(Tree* root, int x);
    Tree* create_element(int value);
    int size(Tree* root);
    void del(Tree*& root, int value);

};

//������� ������� ������: 1. �������� ������, 2. ��������� ����, 3. ���������� ��������� �� ��� ����� �������
Tree* Tree::create_element(int value)
{
    Tree* x = new Tree;
    x->data = value;
    x->left = NULL;
    x->right = NULL;
    return x;
}

//���� ������� � ������ � ������ root
Tree* Tree::search(Tree* root, int x)
{
    if(!root || root->data == x)
    {
        return root;
    }
    if(x<root->data)
    {
        return search(root->left, x);
    }
    return search(root->right, x);
}

//��������� ������� � ������
Tree* Tree::insert(Tree* root, int value)
{
    // ���� ������ �������, ������� ����� ���� � ���������� ���
    if (root == nullptr) {
        auto* x = new Tree{value, nullptr, nullptr};
        root = x;
        return x;
    }
 
    // ���� �������� ������� ������ ��������� ����, ��������� ��� ������ ���������
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // ���� ������ ������� ������, ��� �������� ����, ��������� ��� ������� ���������
    else {
        root->right = insert(root->right, value);
    }
 
    return root;
}

//������� ���������� ����� ������(���������) � ������
int Tree::size(Tree* root)
{
    int count  = 2;
    if(root->left !=NULL)
    {size(root->left);}
    ++count;
    if(root->right != NULL)
    {size(root->right);}
    ++count;
    return count;
}

//������������ ����� � �������
void symmetric(Tree* a, vector<int>& temp)
{
    if(!a){return;}

     else
    {
        symmetric(a->left, temp);
        temp.push_back(a->data);
        //cout << a->data << ", ";
        symmetric(a->right, temp);
    }
}

// ��������������� ������� ��� ������ ���� ������������ �������� � ��������� � ������ curr
Tree* get_minimum_value(Tree* curr)
{
    while (curr->left != nullptr) 
    {
        curr = curr->left;
    }
    return curr;
}

//��������������� ������� ������ �������� �������� ��������
void search_parent(Tree* &curr, int value, Tree* &parent)
{
    // ����� ������ � ����� �����
    while (curr != nullptr && curr->data != value)
    {
        // �������� �������� �� �������� ����
        parent = curr;
 
        // ���� �������� ������� ������ �������� ����, ��������� � ����� ���������;
        // ����� ���� � ������ ���������
        if (value < curr->data) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
}

// ������� ��� �������� ���� �� BST
void Tree::del(Tree*& root, int value)
{
    // ��������� ��� �������� �������� �������� ����
    Tree* parent = nullptr;
 
    // �������� � ��������� ����
    Tree* curr = root;
 
    // ����� ����� � �������� � ��������� ��� ������������� ���������
    search_parent(curr, value, parent);
 
    // ����������, ���� ���� �� ������ 
    if (curr == nullptr) {return;}
 
    // ������ 1: ��������� ���� �� ����� �������� ���������, �. �. �������� �������� �����
    if (curr->left == nullptr && curr->right == nullptr)
    {
        // ���� ��������� ���� �� �������� �������� �����, ������������ �����/������ �������� ������� � null
        if (curr != root)
        {
            if (parent->left == curr) 
            {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
        // ���� ������ ����� ������ �������� ����:
        else {
            root = nullptr;
        }
 
        // ����������� ������
        delete(curr);        
    }
 
    // ������ 2: ��������� ���� ����� ���� ��������
    else if (curr->left && curr->right)
    {
        // ����� ��� ����-��������
        Tree* successor = get_minimum_value(curr->right);
 
        // ��������� ��������
        int val = successor->data;
 
        // ���������� ������� ���������
        del(root, successor->data);
 
        // �������� �������� ��������� � ������� ����
        curr->data = val;
    }
 
    // ������ 3: ��������� ���� ����� ������ ������ �������
    else {
        // �������� �������� ����
        Tree* child = (curr->left)? curr->left: curr->right;
 
        // ���� ��������� ���� �� �������� �������� �����, ������������� ��� �������� ������ �������
        if (curr != root)
        {
            if (curr == parent->left) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
 
        // ���� ��������� ���� �������� �������� �����, �� ���������� ������ ���������
        else {
            root = child;
        }
 
        // ����������� ������
        free(curr);
    }
}