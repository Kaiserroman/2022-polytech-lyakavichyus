// json.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <cstddef>

struct base_token {
    std::string val; // объявляем базированный
};

struct n_token : virtual public base_token {
    template <typename T> n_token(T i) { val = std::to_string(i); } // забиваем в валью значение какого-нибудь i в формате строки
};

struct b_token : virtual public base_token {
    b_token(bool b) { val = b ? "true" : "false"; } // прингимает буловые значения и принимает их в валью 
};

struct s_token : virtual public base_token {
    s_token(std::string s) { val = '"' + s + '"'; } // принимает стринг и "закавычивает"
};

struct arr_token : virtual public base_token {
    arr_token(std::initializer_list<b_token> cont) { // создаём массив, заполненный значениями типа b_token
        val = "["; // начало массива
        for (std::size_t i = 1; auto s : cont) { // заполняем массив значениями, s бежит по cont
            val.append(s.val); // добавляем в конец s-ый элемент 
            if (i != cont.size()) { // если шаг i не равен размеру cont
                val.append(","); // пишем запятую
                i++; // двигаем шаг
            }
        }
        val.append("]");// конец массива
    }
};

struct Json {
    std::unordered_map<std::string, b_token> tokens; // по ключу-строке выводится бул_токен

    Json(std::unordered_map<std::string, b_token> j) { tokens = j; } // объявляем токен объекта класса жсон равный j
    std::string serialize() { // процесс перевода в байты
        std::string out = "{"; // объявляем наш будующий вывод и открываем скобки
        for (std::size_t i = 1; const auto & elem : tokens) { // идём с шагом элем по токену
            out.append("\"" + elem.first + "\":" + elem.second.val); // через мапу обащаемя через фирст - наш ключ стринг, секонд - значение бул
            if (i != tokens.size()) { // если шаг i не равен размеру token
                out.append(","); // пишем запятую
                i++; // двигаем шаг
            }
        }
        out.append("}"); // закрываем скобки
        return out; // выводим
    }
};

/*
int main()
{
    Json json
    {
        unordered_map<string, BasicToken>
        {
            {
                "key", BoolToken(true)
            },
            {
                "str_token", StringToken("Hello, World!")
            },
            {
                "bool_token", BoolToken(true)
            },
            {
                "array_token", ArrayToken
                (
                    {
                        NumToken(88005553535),
                        StringToken("It works!"),
                        BoolToken(false)
                    }
                )
            }
        }
    };
    //cout << json.output() << endl;
    Json json2
    {
        unordered_map <string, BasicToken>
        {
            {"int_token", NumToken(228)}
        }
    };

    cout << json.output() << endl;
    return 0;
}
*/