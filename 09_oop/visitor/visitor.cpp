#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Rectangle; //структура прямоугольник
struct Circle; //круг
struct Triangle; //треугольник

struct IVisitable { //посетитель
    virtual void accept(Rectangle& r) = 0;
    virtual void accept(Circle& c) = 0;
    virtual void accept(Triangle& c) = 0;

    virtual ~IVisitable() {}
};

struct IElement { //элемент
    virtual void visit(IVisitable& v) = 0;

    virtual ~IElement() {}
};

struct Rectangle : IElement {//прямоугольник
    int x, y;//длина шиирина
    Rectangle(int ix, int iy) : x{ ix }, y{ iy } {} //конструктор прямоугльника
    void visit(IVisitable& v) final { v.accept(*this); }
};

struct Circle : IElement { //круг
    int r; //радиус
    Circle(int ir) : r{ ir } {} //конструктор круга
    void visit(IVisitable& v) final { v.accept(*this); }
};

struct Triangle : IElement { //треугольник
    int x, y, z; //стороны стреугольника
    Triangle(int ix, int iy, int iz) : x{ ix }, y{ iy }, z{ iz } {} //конструктор треугольника
    void visit(IVisitable& v) final { v.accept(*this); }
};

struct Printer : IVisitable { //принтер
    void accept(Rectangle& r) final { cout << "Rectangle" << endl; }//пишем что зафигура
    void accept(Circle& c) final { cout << "Circle" << endl; }
    void accept(Triangle& c) final { cout << "Triangle" << endl; }
};

struct Perimeter : IVisitable { //периметр
    void accept(Rectangle& r) final { cout << 2*(r.x + r.y) << endl; }//формула периметра
    void accept(Circle& c) final { cout << c.r * 2 * 3.14 << endl; }
    void accept(Triangle& t) final { cout << t.x + t.y + t.z << endl; }
};

struct Square : IVisitable { //Площадь
    void accept(Rectangle& r) final { cout << r.x * r.y << endl; } //формула площади
    void accept(Circle& c) final { cout << c.r * c.r * 3.14 << endl; }
    void accept(Triangle& t) final { cout << sqrt(((t.x+t.y+t.z)/2)*((t.x + t.y + t.z) / 2-t.x)*((t.x + t.y + t.z) / 2 - t.y)*((t.x + t.y + t.z) / 2 - t.z)) << endl; }//многабукаф - геррон
};

int main() {
    std::vector<IElement*> elements;

    elements.push_back(new Circle{ 5 });
    elements.push_back(new Rectangle{ 12, 4 });
    elements.push_back(new Triangle{ 3, 4, 5 });

    Perimeter p;
    for (auto& el : elements) {
        el->visit(p);
    }

    Square s;
    for (auto& el : elements) {
        el->visit(s);
    }
}
