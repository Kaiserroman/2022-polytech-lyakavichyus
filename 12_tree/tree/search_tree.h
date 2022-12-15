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

//Создаем элемент дерева: 1. выделяем память, 2. заполняем поля, 3. возвращаем указатель на наш новый элемент
Tree* Tree::create_element(int value)
{
    Tree* x = new Tree;
    x->data = value;
    x->left = NULL;
    x->right = NULL;
    return x;
}

//ищем элемент в дереве с корнем root
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

//вставляем вершину в дерево
Tree* Tree::insert(Tree* root, int value)
{
    // если корень нулевой, создаем новый узел и возвращаем его
    if (root == nullptr) {
        auto* x = new Tree{value, nullptr, nullptr};
        root = x;
        return x;
    }
 
    // если заданный элемент меньше корневого узла, повторить для левого поддерева
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // если данный элемент больше, чем корневой узел, повторить для правого поддерева
    else {
        root->right = insert(root->right, value);
    }
 
    return root;
}

//функция возвращает число вершин(элементов) в дереве
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

//симметричный обход в глубину
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

// Вспомогательная функция для поиска узла минимального значения в поддереве с корнем curr
Tree* get_minimum_value(Tree* curr)
{
    while (curr->left != nullptr) 
    {
        curr = curr->left;
    }
    return curr;
}

//вспомогательная функция поиска родителя текущего элемента
void search_parent(Tree* &curr, int value, Tree* &parent)
{
    // обход дерева и поиск ключа
    while (curr != nullptr && curr->data != value)
    {
        // обновить родителя до текущего узла
        parent = curr;
 
        // если заданный элемент меньше текущего узла, переходим в левое поддерево;
        // иначе идем в правое поддерево
        if (value < curr->data) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
}

// Функция для удаления узла из BST
void Tree::del(Tree*& root, int value)
{
    // указатель для хранения родителя текущего узла
    Tree* parent = nullptr;
 
    // начинаем с корневого узла
    Tree* curr = root;
 
    // поиск ключа в бинарном и установка его родительского указателя
    search_parent(curr, value, parent);
 
    // возвращаем, если ключ не найден 
    if (curr == nullptr) {return;}
 
    // Случай 1: удаляемый узел не имеет дочерних элементов, т. е. является листовым узлом
    if (curr->left == nullptr && curr->right == nullptr)
    {
        // если удаляемый узел не является корневым узлом, родительский левый/правый дочерний элемент в null
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
        // если дерево имеет только корневой узел:
        else {
            root = nullptr;
        }
 
        // освобождаем память
        delete(curr);        
    }
 
    // Случай 2: удаляемый узел имеет двух потомков
    else if (curr->left && curr->right)
    {
        // найти его узел-преемник
        Tree* successor = get_minimum_value(curr->right);
 
        // сохраняем значение
        int val = successor->data;
 
        // рекурсивно удаляем преемника
        del(root, successor->data);
 
        // копируем значение преемника в текущий узел
        curr->data = val;
    }
 
    // Случай 3: удаляемый узел имеет только одного потомка
    else {
        // выбираем дочерний узел
        Tree* child = (curr->left)? curr->left: curr->right;
 
        // если удаляемый узел не является корневым узлом, устанавливаем его родителя своему потомку
        if (curr != root)
        {
            if (curr == parent->left) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
 
        // если удаляемый узел является корневым узлом, то установить корень дочернему
        else {
            root = child;
        }
 
        // освобождаем память
        free(curr);
    }
}