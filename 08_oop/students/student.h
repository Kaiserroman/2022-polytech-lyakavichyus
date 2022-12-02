// student.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once
#include <cstring>
#include <initializer_list>
#include <iostream>

struct Student { //класс студент
    const char* name; // строка-массив имя
    int score;// переменная оценка

    friend std::ostream& operator<<(std::ostream& out, Student& s) { //оператор вывода 
        out << "{name: \"" << s.name << "\", score: " << s.score << "}";
        return out;
    }

    const bool operator==(const Student& s) const { //оператор сравнения
        return !(std::strcmp(name, s.name)) && score == s.score;
    }

    const bool operator!=(const Student& s) const { return !(*this == s); }
};

class StudentList { //класс список 
private:
    Student* _stud; // студент в списке
    std::size_t _size;// переменная максимально доступного размера (длина списка)

    StudentList& _set_score(const char* n, int ns) { //метод поставить оценку 
        for (std::size_t i = 0; i < _size; ++i) {//идём по списку
            if (!std::strcmp(_stud[i].name, n)) {//ищем н ученика
                _stud[i].score = ns;//меняем оценку
                return *this; //возвращаем получившийся список
            }
        }
        return *this; //возвращаем получившийся список
    }

    StudentList& _remove(const char* n) { //метод удаление из списка 
        for (std::size_t i = 0; i < _size; ++i) { //идём по списку 
            if (!std::strcmp(_stud[i].name, n)) { //если это нежеланный студент
                for (std::size_t x = i; x < _size - 1; ++x)//идём по списку студентов с н-ого номера (нежелательного)
                    _stud[x] = _stud[x + 1]; //заменяем на следующего
                Student* tmp = //временный список
                    (Student*)std::realloc(_stud, (_size - 1) * sizeof(Student)); //меняем размер занимаемой списокм памяти с учётом новго студента
                if (tmp == NULL && _size > 1)
                    exit(EXIT_FAILURE); // если пустой список, хотя есть позиции выдаём ошибку
                _size--;//укорачиваем список на одного отчисленного
                _stud = tmp; //присваем нашему списку получившийся без ученика
                return *this; //возвращаем новый список
            }
        }
        return *this; //возвращаем список
    }

public:
    StudentList() : _size{ 0 } {}

    StudentList(std::initializer_list<Student> list) //конструктор
        : _stud{ new Student[list.size()] }, _size{ list.size() } {
        for (std::size_t i = 0; const auto & elem : list) {
            _stud[i] = elem;
            i++;
        }
    }

    StudentList(const StudentList& other) : _size{ other._size } { //конструктор
        delete[] _stud;
        _stud = other._stud;
    }

    ~StudentList() { //деструктор
        if (_stud) {
            delete[] _stud;
            _stud = nullptr;
        }
    };

public:
    StudentList& operator=(const StudentList& other) { //оператор присваивания(ввода)
        if (this == &other)
            return *this;
        _size = other._size;
        _stud = (Student*)std::realloc(_stud, _size * sizeof(Student));
        for (std::size_t i = 0; i != _size; ++i)
            _stud[i] = other._stud[i];
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, StudentList& sl) { //оператор вывода
        if (sl._size == 0) {
            out << "[]";
            return out;
        }
        out << "[\n";
        for (std::size_t i = 0; i < sl._size; ++i) {
            out << "  " << sl._stud[i];
            if (i + 1 != sl._size)
                out << ", \n";
        }
        out << "\n]";
        return out;
    }

    const bool operator==(const StudentList& sl) const {//оператор сравнения
        if (sl._size != _size)
            return false;
        for (std::size_t i = 0; i != _size; ++i) {
            if (_stud[i] != sl._stud[i])
                return false;
        }
        return true;
    }

public:
    // Добавляем объёкт студент в список-массив
    StudentList& append(Student& stud) { 
        _size++; 
        auto tmp = new Student[_size];
        for (std::size_t i = 0; i < _size - 1; ++i)  
            tmp[i] = _stud[i]; 
        tmp[_size - 1] = stud; 
        delete[] _stud;
        _stud = tmp;
        return *this;
    }
    StudentList& append(const char* n, int s) {
        auto stud = Student{ n, s };
        return this->append(stud);
    }

    /// Удаляем студентов по имени/оценке
    StudentList& remove(const char* n) { return _remove(n); }
    StudentList& remove(Student& s) { return _remove(s.name); }

    /// Выставляем оценку студенту
    StudentList& set_score(const char* n, int ns) { return _set_score(n, ns); }
    StudentList& set_score(Student& sl, int ns) {
        return _set_score(sl.name, ns);
    }

    /// Берём среднюю оценку стунетов
    double get_avg_score() const {
        double score_sum = 0;
        for (std::size_t i = 0; i < _size; ++i) {
            score_sum += _stud[i].score;
        }
        return score_sum / _size;
    }

    Student find_student(const char* n) {
        for (std::size_t i = 0; i < _size; ++i) {
            if (!std::strcmp(_stud[i].name, n))
                return _stud[i];
        }
        return Student{};
    }

    /// Выводим список студентов с оценков выше 6
    StudentList get_best_students() const {
        StudentList best_students{};
        for (std::size_t i = 0; i < _size; ++i) {
            if (_stud[i].score > 6)
                best_students.append(_stud[i]);
        }
        return best_students;
    }

    /// Выводим список студентов с оценкой ниже 4
    StudentList get_worst_students() const {
        StudentList worst_students{};
        for (std::size_t i = 0; i < _size; ++i) {
            if (_stud[i].score < 4)
                worst_students.append(_stud[i]);
        }
        return worst_students;
    }
};

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
