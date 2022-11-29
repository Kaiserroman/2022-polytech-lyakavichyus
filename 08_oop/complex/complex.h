class Complex {//объявляем класс
public:
	int r_part; //объявляем целую часть
	int i_part; //объявляем часть с мнимой единицей
	Complex(int r, int i) : r_part(r), i_part(i) {}; //объявляем консруктор
	const Complex operator+(const Complex rv) const; //объявляем оператор сложения
	const Complex operator-(const Complex rv) const; //объявляем опреатор вычитания 
	const bool operator==(const Complex rv) const; //объявляем оператор сравнения
	const double abs() const; //объявляем оператор модуля
};
