#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
#include "node.h"

using namespace std;

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");

    Queue queue;
    Stack stack;
    Array array;
    string command, value;

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


        // DubleList (ДВУСВЯЗНЫЙ СПИСОК)
        // HashTable (ХЕШ-ТАБЛИЦА)
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

    return 0;
}