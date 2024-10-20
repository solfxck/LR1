#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;

void loadQueueFromFile(Queue& queue, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        string value;
        while (getline(inputFile, value)) {
            queue.push(value);
        }
        inputFile.close();
    }
}

void loadStackFromFile(Stack& stack, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        string values[100];
        int count = 0;
        string value;
        while (getline(inputFile, value)) {
            values[count] = value;
            count++;
        }
        inputFile.close();

        for (int i = count - 1; i >= 0; i--) {
            stack.push(values[i]);
        }
    }
}

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

void loadListFromFile(List& list, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        string value;
        while (getline(inputFile, value)) {
            list.pushTail(value);
        }
        inputFile.close();
    }
}

void loadDubleListFromFile(DubleList& dubleList, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        string value;
        while (getline(inputFile, value)) {
            dubleList.pushTail(value);
        }
        inputFile.close();
    }
}

void loadHashTableFromFile(HashTable& hashTable, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        string key, value;
        while (inputFile >> key >> value) {
            hashTable.insert(key, value);
        }
        inputFile.close();
    }
}

void loadAVLFromFile(AVL& avl, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        int key;
        while (inputFile >> key) {
            avl.insert(key);
        }
        inputFile.close();
    }
}

void saveQueueToFile(Queue& queue, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        Node* current = queue.head;
        while (current != nullptr) {
            outputFile << current->data << endl;
            current = current->next;
        }
        outputFile.close();
    }
}

void saveStackToFile(Stack& stack, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        Node* current = stack.top;
        while (current != nullptr) {
            outputFile << current->data << endl;
            current = current->next;
        }
        outputFile.close();
    }
}

void saveArrayToFile(Array& array, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (int i = 0; i < array.length(); i++) {
            outputFile << array.get(i) << endl;
        }
        outputFile.close();
    }
}

void saveListToFile(List& list, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        Node* current = list.head;
        while (current != nullptr) {
            outputFile << current->data << endl;
            current = current->next;
        }
        outputFile.close();
    }
}

void saveDubleListToFile(DubleList& dubleList, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        Node* current = dubleList.head;
        while (current != nullptr) {
            outputFile << current->data << endl;
            current = current->next;
        }
        outputFile.close();
    }
}

void saveHashTableToFile(HashTable& hashTable, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (int i = 0; i < hashTable.size; i++) {
            NodeHT* current = hashTable.table[i];
            while (current != nullptr) {
                outputFile << current->key << " " << current->value << endl;
                current = current->next;
            }
        }
        outputFile.close();
    }
}

void saveAVLToFile(AVL& avl, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        avl.saveToFile(avl.root, outputFile);
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