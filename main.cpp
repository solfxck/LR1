#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;

// ------------- ЗАГРУЗКА из файла -------------

// функция для загрузки данных в очередь из файла
void loadQueueFromFile(Queue& queue, const string& filename) {
    ifstream inputFile(filename); // открываем файл для чтения
    if (inputFile.is_open()) { // проверяем, удалось ли открыть файл
        string value;
        while (getline(inputFile, value)) { // читаем строки из файла
            queue.push(value); // добавляем строку в очередь
        }
        inputFile.close(); // закрываем файл
    }
}

// функция для загрузки данных в стек из файла
void loadStackFromFile(Stack& stack, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        string values[100]; // для хранения строк
        int count = 0;
        string value;
        while (getline(inputFile, value)) {
            values[count] = value; // сохраняем строку в массив
            count++;
        }
        inputFile.close();

        for (int i = count - 1; i >= 0; i--) { // добавляем строки в стек в обратном порядке
            stack.push(values[i]);
        }
    }
}

// функция для загрузки данных в массив из файла
void loadArrayFromFile(Array& array, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        string value;
        while (getline(inputFile, value)) {
            array.pushEnd(value);
        }
        inputFile.close();
    }
}

// функция для загрузки данных в список из файла
void loadListFromFile(List& list, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        string value;
        while (getline(inputFile, value)) {
            list.pushTail(value); // добавляем строку в конец списка
        }
        inputFile.close();
    }
}

// функция для загрузки данных в двусвязный список из файла
void loadDubleListFromFile(DubleList& dubleList, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        string value;
        while (getline(inputFile, value)) {
            dubleList.pushTail(value); // добавляем строку в конец двусвязного списка
        }
        inputFile.close();
    }
}

// функция для загрузки данных в хеш-таблицу из файла
void loadHashTableFromFile(HashTable& hashTable, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        string key, value;
        while (inputFile >> key >> value) { // читаем пары ключ-значение из файла
            hashTable.insert(key, value); // добавляем пару в хеш-таблицу
        }
        inputFile.close();
    }
}

// функция для загрузки данных в АВЛ-дерево из файла
void loadAVLFromFile(AVL& avl, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        int key;
        while (inputFile >> key) { // читаем ключи из файла
            avl.insert(key); // добавляем ключ в АВЛ-дерево
        }
        inputFile.close();
    }
}

// ------------- СОХРАНЕНИЕ в файл -------------

// функция для сохранения данных из очереди в файл
void saveQueueToFile(Queue& queue, const string& filename) {
    ofstream outputFile(filename); // открываем файл для записи
    if (outputFile.is_open()) { // проверяем, удалось ли открыть файл
        Node1* current = queue.head;
        while (current != nullptr) { // проходим по очереди
            outputFile << current->data << endl; // записываем данные в файл
            current = current->next;
        }
        outputFile.close(); // закрываем файл
    }
}

// функция для сохранения данных из стека в файл
void saveStackToFile(Stack& stack, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        Node1* current = stack.top;
        while (current != nullptr) { // проходим по стеку
            outputFile << current->data << endl; // записываем данные в файл
            current = current->next;
        }
        outputFile.close(); // закрываем файл
    }
}

// функция для сохранения данных из массива в файл
void saveArrayToFile(Array& array, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (int i = 0; i < array.length(); i++) {
            outputFile << array.get(i) << endl;
        }
        outputFile.close();
    }
}

// функция для сохранения данных из списка в файл
void saveListToFile(List& list, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        Node1* current = list.head;
        while (current != nullptr) { // проходим по списку
            outputFile << current->data << endl; // записываем данные в файл
            current = current->next;
        }
        outputFile.close(); // закрываем файл
    }
}

// функция для сохранения данных из двусвязного списка в файл
void saveDubleListToFile(DubleList& dubleList, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        Node* current = dubleList.head;
        while (current != nullptr) { // проходим по двусвязному списку
            outputFile << current->data << endl; // записываем данные в файл
            current = current->next;
        }
        outputFile.close(); // закрываем файл
    }
}

// функция для сохранения данных из хеш-таблицы в файл
void saveHashTableToFile(HashTable& hashTable, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (int i = 0; i < hashTable.size; i++) { // проходим по хеш-таблице
            NodeHT* current = hashTable.table[i];
            while (current != nullptr) { // проходим по связанному списку
                outputFile << current->key << " " << current->value << endl; // записываем данные в файл
                current = current->next;
            }
        }
        outputFile.close(); // закрываем файл
    }
}

// функция для сохранения данных из АВЛ-дерева в файл
void saveAVLToFile(AVL& avl, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        avl.saveToFile(avl.root, outputFile); // записываем данные в файл
        outputFile.close();
    }
}

void processCommand(const string& command, Queue& queue, Stack& stack, Array& array, List& list, DubleList& dubleList, HashTable& hashTable, AVL& avl) {
    string key, value;
    int intKey;
    if (command == "EXIT") {
        return;
    }
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
    else if (command.at(0) == 'M') { // команды для массива
        if (command == "MPUSH_T") { // добавление в конец
            cin >> value;
            array.pushEnd(value);
        }
        else if (command == "MPUSH_ID") { // добавление по индексу
            int index;
            cin >> index >> value;
            array.push(index, value);
        }
        else if (command == "MGET") { // получение по индексу
            int index;
            cin >> index;
            cout << array.get(index) << endl;
        }
        else if (command == "MPOP_ID") { // удаление по индексу
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
    else if (command.at(0) == 'L') { // Команды для списка
        if (command == "LPUSH_H") { // Добавление в начало
            cin >> value;
            list.pushHead(value);
        }
        else if (command == "LPUSH_T") { // Добавление в конец
            cin >> value;
            list.pushTail(value);
        }
        else if (command == "LPOP_H") { // Удаление с начала
            list.popHead();
        }
        else if (command == "LPOP_T") { // Удаление с конца
            list.popTail();
        }
        else if (command == "LPOP_V") { // Удаление по значению
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
    else if (command.at(0) == 'H') { // Команды для хеш-таблицы
        if (command == "HPUSH") { // Добавление или обновление элемента
            cin >> key >> value;
            hashTable.insert(key, value);
        }
        else if (command == "HGET") { // Получение элемента
            cin >> key;
            cout << hashTable.get(key) << endl;
        }
        else if (command == "HPOP") { // Удаление элемента
            cin >> key;
            hashTable.remove(key);
        }
        else if (command == "HPRINT") { // Вывод хеш-таблицы
            hashTable.display();
        }
        else {
            cout << "Неверная команда." << endl;
        }
    }
    else if (command.at(0) == 'T') { // Команды для АВЛ-дерева
        if (command == "TPUSH") { // Добавление элемента
            cin >> intKey;
            avl.insert(intKey);
        }
        else if (command == "TPOP") { // Удаление элемента
            cin >> intKey;
            avl.remove(intKey);
        }
        else if (command == "TSEARCH") { // Поиск элемента
            cin >> intKey;
            if (avl.search(intKey)) {
                cout << "Элемент найден" << endl;
            }
            else {
                cout << "Элемент не найден" << endl;
            }
        }
        else if (command == "TPRINT") { // Вывод дерева
            avl.display();
        }
        else {
            cout << "Неверная команда." << endl;
        }
    }
    else {
        cout << "Неверная команда." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    Queue queue;
    Stack stack;
    Array array;
    List list;
    DubleList dubleList;
    HashTable hashTable;
    AVL avl;

    loadQueueFromFile(queue, "txt/queue.txt");
    loadStackFromFile(stack, "txt/stack.txt");
    loadArrayFromFile(array, "txt/array.txt");
    loadListFromFile(list, "txt/list.txt");
    loadDubleListFromFile(dubleList, "txt/dublelist.txt");
    loadHashTableFromFile(hashTable, "txt/hashtable.txt");
    loadAVLFromFile(avl, "txt/avl.txt");

    string command;
    while (true) {
        cout << "> ";
        cin >> command;
        if (command == "EXIT") {
            break;
        }
        processCommand(command, queue, stack, array, list, dubleList, hashTable, avl);
    }

    saveQueueToFile(queue, "txt/queue.txt");
    saveStackToFile(stack, "txt/stack.txt");
    saveArrayToFile(array, "txt/array.txt");
    saveListToFile(list, "txt/list.txt");
    saveDubleListToFile(dubleList, "txt/dublelist.txt");
    saveHashTableToFile(hashTable, "txt/hashtable.txt");
    saveAVLToFile(avl, "txt/avl.txt");

    return 0;
}