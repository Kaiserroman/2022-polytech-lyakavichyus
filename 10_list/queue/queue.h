struct QKey { //структура узел очереди
    int data; //значние очереди
    QKey* next; //указатель в узле
    QKey(int d) {
        data = d;
        next = nullptr;
    } //конструктор
};

struct Queue {
    QKey* first, * last;// первыый и последний узлы 
    Queue() { first = last = nullptr; } //очердь от первого до последнего, а далее нул

    void enqueue(int x) { //вставить в очередь
        QKey* temp = new QKey(x); //временный узел

        if (last == nullptr) {// если последний нуль
            first = last = temp; //то последний теперь временный
            return;
        }

        last->next = temp; //согласуем указатели
        last = temp;
    }

    void dequeue() { //удаление из очереди
        if (first == nullptr) return; //если первый элемент - 0, ничего не делаем
        QKey* temp = first; //временный узел
        first = first->next; //указатель на первый, теперь указывает на следющий
        if (first == nullptr) last = nullptr; //если первый указывает на ноль, то последний раен нулю - frist=last
        delete (temp); //удаляем узел
    }
};