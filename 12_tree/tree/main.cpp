#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "search_tree.h"
#include "doctest.h"
using namespace std;

//SYMMETRIC CHECK
TEST_CASE("SYMMETRIC")
{
    auto* a = new Tree{ 2, nullptr, nullptr };
    auto* b = new Tree{ 1, nullptr, nullptr };
    auto* c = new Tree{ 0, nullptr, nullptr };
    auto* d = new Tree{ 10,nullptr, nullptr };
    a->left = b;
    a->left->left = c;
    a->right = d;

    vector<int> eth1 = { 0, 1, 2, 10 };
    vector<int> temp;
    symmetric(a, temp);

    CHECK(temp[0] == eth1[0]);
    CHECK(temp[1] == eth1[1]);
    CHECK(temp[2] == eth1[2]);
    CHECK(temp[3] == eth1[3]);
}

//INSERT CHECK 
TEST_CASE("INSERT")
{
    auto* a = new Tree{ 2, nullptr, nullptr };
    auto* b = new Tree{ 1, nullptr, nullptr };
    auto* c = new Tree{ 0, nullptr, nullptr };
    auto* d = new Tree{ 10,nullptr, nullptr };
    a->left = b;
    a->left->left = c;
    a->right = d;

    vector<int> eth1 = { 0, 1, 2, 7, 10 };
    vector<int> temp;
    symmetric(a->insert(a, 7), temp);

    CHECK(temp[0] == eth1[0]);
    CHECK(temp[1] == eth1[1]);
    CHECK(temp[2] == eth1[2]);
    CHECK(temp[3] == eth1[3]);
    CHECK(temp[4] == eth1[4]);
}


//SIZE CHECK 
TEST_CASE("SIZE")
{
    auto* a = new Tree{ 2, nullptr, nullptr };
    auto* b = new Tree{ 1, nullptr, nullptr };
    auto* c = new Tree{ 0, nullptr, nullptr };
    auto* d = new Tree{ 10,nullptr, nullptr };
    a->left = b;
    a->left->left = c;
    a->right = d;
    CHECK(a->size(a) == 4);
}

//DELETE CHECK 
TEST_CASE("DELETE")
{
    auto* a = new Tree{ 2, nullptr, nullptr };
    auto* b = new Tree{ 1, nullptr, nullptr };
    auto* c = new Tree{ 0, nullptr, nullptr };
    auto* d = new Tree{ 10,nullptr, nullptr };
    a->left = b;
    a->left->left = c;
    a->right = d;

    vector<int> eth1 = { 0, 1, 2 };
    vector<int> temp;
    a->del(a, 10);
    symmetric(a, temp);

    CHECK(temp[0] == eth1[0]);
    CHECK(temp[1] == eth1[1]);
    CHECK(temp[2] == eth1[2]);
}

//SEARCH CHECK 
TEST_CASE("SEARCH")
{
    auto* a = new Tree{ 2, nullptr, nullptr };
    auto* b = new Tree{ 1, nullptr, nullptr };
    auto* c = new Tree{ 0, nullptr, nullptr };
    auto* d = new Tree{ 10,nullptr, nullptr };
    a->left = b;
    a->left->left = c;
    a->right = d;

    int srch = a->search(a, 2)->data;

    CHECK(srch == 2);
}



/*
#include "search_tree.h"
using namespace std;

template <typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& vec)
{
    for (auto elem : vec)
    {
        os << elem << " ";
    }
    return os;
}

int main()
{
    auto* a = new Tree{2, nullptr, nullptr};
    auto* b = new Tree{1, nullptr, nullptr};
    auto* c = new Tree{0, nullptr, nullptr};
    auto* d = new Tree{10,nullptr, nullptr};
    
    a->left = b;
    a->left->left = c;
    a->right = d;
        
    vector<int> vect;

    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);

    vector<int> v1;
    symmetric(a, v1);
    cout << v1;
    

    /*
    symmetric(a, v1);
    for(int i=0; i <v.size(); i++) {

       cout <<a.at(i) <<' '; }

    a->del(a,10);
    cout << endl << endl;
    symmetric(a, v2);
    cout << endl << endl;
    int count = a->size(a);
    cout << count << endl << endl;
    Tree* i = a->search(a, 0);
    cout << i->data << endl << endl;
    a->insert(a,4);
    symmetric(a, v3);
    
    
    delete a;
    delete b;
    delete c;

    system("pause 0");
    return 0;
}
*/