#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
#include "node.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Queue queue;
    Stack stack;
    Array array;
    List list;
    DubleList dubleList;
    HashTable hashTable(1);
    string command, key, value;

    // загрузка очереди из файла
    ifstream inputFile("queue.txt");
    if (inputFile.is_open()) {
        while (getline(inputFile, value)) {
            queue.push(value);
        }
        inputFile.close();
    }

    // загрузка стека из файла
    inputFile.open("stack.txt");
    if (inputFile.is_open()) {
        string values[100]; // для хранения элементов
        int count = 0;

        while (getline(inputFile, value)) {
            values[count] = value;
            count++;
        }
        inputFile.close();

        // добавляем элементы в стек в обратном порядке
        for (int i = count - 1; i >= 0; i--) {
            stack.push(values[i]);
        }
    }

    // загрузка массива из файла
    inputFile.open("array.txt");
    if (inputFile.is_open()) {
        while (getline(inputFile, value)) {
            array.pushEnd(value);
        }
        inputFile.close();
    }

    // Загрузка списка из файла
    inputFile.open("list.txt");
    if (inputFile.is_open()) {
        while (getline(inputFile, value)) {
            list.pushTail(value);
        }
        inputFile.close();
    }

    // загрузка двусвязного списка из файла
    inputFile.open("dublelist.txt");
    if (inputFile.is_open()) {
        while (getline(inputFile, value)) {
            dubleList.pushTail(value);
        }
        inputFile.close();
    }

    // загрузка хеш-таблицы из файла
    inputFile.open("hashtable.txt");
    if (inputFile.is_open()) {
        while (getline(inputFile, key)) {
            getline(inputFile, value);
            hashTable.put(key, value);
        }
        inputFile.close();
    }

    while (true) {
        cout << "> ";
        cin >> command;

        if (command == "EXIT") {
            break;
        }

        // Queue (ОЧЕРЕДЬ)
        else if (command.at(0) == 'Q') { // команды для очереди
            if (command == "QPUSH") {
                cin >> value;
                queue.push(value);
            }
            else if (command == "QPOP") {
                queue.pop();
            }
            else if (command == "QPRINT") {
                queue.display();
            }
            else {
                cout << "Неверная команда." << endl;
            }
        }

        // Stack (СТЕК)
        else if (command.at(0) == 'S') { // команды для стека
            if (command == "SPUSH") {
                cin >> value;
                stack.push(value);
            }
            else if (command == "SPOP") {
                stack.pop();
            }
            else if (command == "SPRINT") {
                stack.display();
            }
            else {
                cout << "Неверная команда." << endl;
            }
        }

        // Array (МАССИВ)
        else if (command.at(0) == 'M') { // команды для массива
            if (command == "MPUSH") { // добавление в конец
                cin >> value;
                array.pushEnd(value);
            }
            else if (command == "MPUSHID") { // добавление по индексу
                int index;
                cin >> index >> value;
                array.push(index, value);
            }
            else if (command == "MGET") { // получение по индексу
                int index;
                cin >> index;
                cout << array.get(index) << endl;
            }
            else if (command == "MPOPID") { // удаление по индексу
                int index;
                cin >> index;
                array.pop(index);
            }
            else if (command == "MREP") { // замена по индексу
                int index;
                cin >> index >> value;
                array.replace(index, value);
            }
            else if (command == "MLEN") { // длина массива
                cout << array.length() << endl;
            }
            else if (command == "MPRINT") { // вывод массива
                array.display();
            }
            else {
                cout << "Неверная команда." << endl;
            }
        }

        // List (ОДНОСВЗЯНЫЙ СПИСОК)
        else if (command.at(0) == 'L') { // Команды для списка
            if (command == "LPUSHHEAD") { // Добавление в начало
                cin >> value;
                list.pushHead(value);
            }
            else if (command == "LPUSHTAIL") { // Добавление в конец
                cin >> value;
                list.pushTail(value);
            }
            else if (command == "LPOPHEAD") { // Удаление с начала
                list.popHead();
            }
            else if (command == "LPOPTAIL") { // Удаление с конца
                list.popTail();
            }
            else if (command == "LPOPVALUE") { // Удаление по значению
                cin >> value;
                list.popValue(value);
            }
            else if (command == "LSEARCH") { // Поиск по значению
                cin >> value;
                if (list.search(value)) {
                    cout << "Элемент найден" << endl;
                }
                else {
                    cout << "Элемент не найден" << endl;
                }
            }
            else if (command == "LPRINT") { // Вывод списка
                list.display();
            }
            else {
                cout << "Неверная команда." << endl;
            }
        }

        // DubleList (ДВУСВЯЗНЫЙ СПИСОК)
        else if (command.at(0) == 'D') { // Команды для двусвязного списка
            if (command == "DPUSH_H") { // Добавление в начало
                cin >> value;
                dubleList.pushHead(value);
            }
            else if (command == "DPUSH_T") { // Добавление в конец
                cin >> value;
                dubleList.pushTail(value);
            }
            else if (command == "DPOP_H") { // Удаление с начала
                dubleList.popHead();
            }
            else if (command == "DPOP_T") { // Удаление с конца
                dubleList.popTail();
            }
            else if (command == "DPOP_V") { // Удаление по значению
                cin >> value;
                dubleList.popValue(value);
            }
            else if (command == "DSEARCH") { // Поиск по значению
                cin >> value;
                if (dubleList.search(value)) {
                    cout << "Элемент найден" << endl;
                }
                else {
                    cout << "Элемент не найден" << endl;
                }
            }
            else if (command == "DPRINT") { // Вывод списка
                dubleList.display();
            }
            else {
                cout << "Неверная команда." << endl;
            }
        }

        // HashTable (ХЕШ-ТАБЛИЦА)
        else if (command.at(0) == 'H') { // Команды для хеш-таблицы
            if (command == "HPUT") { // Добавление элемента
                cin >> key >> value;
                hashTable.put(key, value);
            }
            else if (command == "HGET") { // Получение значения по ключу
                cin >> key;
                cout << hashTable.get(key) << endl;
            }
            else if (command == "HREM") { // Удаление элемента по ключу
                cin >> key;
                if (hashTable.remove(key)) {
                    cout << " удален" << endl;
                }
                else {
                    cout << "Элемент не найден" << endl;
                }
            }
            else {
                cout << "Неверная команда." << endl;
            }
        }
        // AVL (АВЛ-ДЕРЕВО)

        else {
            cout << "Неверная команда." << endl;
        }
    }

    // сохранение очереди в файл
    ofstream outputFile("queue.txt");
    if (outputFile.is_open()) {
        Node* current = queue.head;
        while (current != nullptr) {
            outputFile << current->data << endl;
            current = current->next;
        }
        outputFile.close();
    }

    // сохранение стека в файл
    outputFile.open("stack.txt");
    if (outputFile.is_open()) {
        Node* current = stack.top;
        while (current != nullptr) {
            outputFile << current->data << endl;
            current = current->next;
        }
        outputFile.close();
    }

    // сохранение массива в файл
    outputFile.open("array.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i < array.length(); i++) {
            outputFile << array.get(i) << endl;
        }
        outputFile.close();
    }

    // Сохранение списка в файл
    outputFile.open("list.txt");
    if (outputFile.is_open()) {
        Node* current = list.head;
        while (current != nullptr) {
            outputFile << current->data << endl;
            current = current->next;
        }
        outputFile.close();
    }

    // cохранение двусвязного списка в файл
    outputFile.open("dublelist.txt");
    if (outputFile.is_open()) {
        Node* current = dubleList.head;
        while (current != nullptr) {
            outputFile << current->data << endl;
            current = current->next;
        }
        outputFile.close();
    }

    // Сохранение хеш-таблицы в файл
    outputFile.open("hashtable.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i < hashTable.size; ++i) {
            NodeHT* current = hashTable.table[i];
            while (current != nullptr) {
                outputFile << current->key << endl;
                outputFile << current->value << endl;
                current = current->next;
            }
        }
        outputFile.close();
    }

    return 0;
}