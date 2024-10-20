#include "header.h"
#include <iostream>
#include <string>

using namespace std;

// конструктор хеш-таблицы
HashTable::HashTable() {
    for (int i = 0; i < size; i++) {
        table[i] = nullptr;  // каждая ячейка становится пустой
    }
}

// функция для вычисления основного хеш-значения
int HashTable::hashFunction(const string& key) {
    int hash = 0;
    for (size_t i = 0; i < key.length(); i++) {
        hash += key[i];  // добавляем ASCII код символа к хешу
    }
    return hash % size;  // возвращаем остаток от деления на размер таблицы (для распределения значений по индексам)
}

// двойного хеширования (чтобы избежать коллизий)
int HashTable::hashFunction2(const string& key) {
    int hash = 0;
    for (size_t i = 0; i < key.length(); i++) {
        hash += key[i];  // добавляем ASCII код символа к хешу
    }
    return 7 - (hash % 7);  // возврат простого числа для уменьшения коллизий (7 - простое и меньше размера таблицы)
}

// Сложность: O(n) (в худшем случае)
void HashTable::insert(const string& key, const string& value) {
    int index = hashFunction(key);  // вычисляем первый хеш
    int step = hashFunction2(key);  // вычисляем шаг для двойного хеширования

    // цикл пытается найти подходящее место для вставки элемента
    for (int i = 0; i < size; i++) {
        int newIndex = (index + i * step) % size;  // находим новый индекс с шагом
        if (table[newIndex] == nullptr) { // если ячейка пуста, создаем новый узел и вставляем
            table[newIndex] = new NodeHT(key, value);
            return;
        } 
        else if (table[newIndex]->key == key) { // если ключ уже существует, обновляем значение
            table[newIndex]->value = value;
            return;
        }
    }
    cout << "Хеш-таблица заполнена, невозможно добавить элемент." << endl;
}

// Сложность: O(n) (в худшем случае)
string HashTable::get(const string& key) {
    int index = hashFunction(key);  // вычисляем первый хеш
    int step = hashFunction2(key);  // вычисляем шаг для двойного хеширования

    // цикл пытается найти нужный элемент по ключу
    for (int i = 0; i < size; i++) {
        int newIndex = (index + i * step) % size;  // находим новый индекс с шагом
        if (table[newIndex] != nullptr && table[newIndex]->key == key) { // если ключ найден, возвращаем его значение
            return table[newIndex]->value;
        }
    }
    return "Элемент не найден";  // если элемент не найден
}

// Сложность O(n) (в худшем случае: если удаляемый элемент находится в последней возможной ячейке)
void HashTable::remove(const string& key) {
    int index = hashFunction(key);  // вычисляем первый хеш
    int step = hashFunction2(key);  // вычисляем шаг для двойного хеширования

    // цикл ищет элемент для удаления
    for (int i = 0; i < size; i++) {
        int newIndex = (index + i * step) % size;  // находим новый индекс с шагом
        if (table[newIndex] != nullptr && table[newIndex]->key == key) { // если ключ найден, удаляем элемент
            delete table[newIndex];  // освобождаем память
            table[newIndex] = nullptr;  // отмечаем ячейку как пустую
            return;
        }
    }
    cout << "Элемент не найден" << endl;  // если элемент не найден
}

// Сложность: O(n)
void HashTable::display() {
    for (int i = 0; i < size; i++) {
        if (table[i] != nullptr) {
            cout << "[" << i << "] " << table[i]->key << ": " << table[i]->value << endl;
        } 
        else {
            cout << "[" << i << "] Пусто" << endl;
        }
    }
}