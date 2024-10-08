#include "header.h"
#include "node.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size) {
    this->size = size;
    table = new NodeHT * [size];
    for (int i = 0; i < size; ++i) {
        table[i] = nullptr;
    }
}

int HashTable::hashFunction(string key) {
    int hash = 0;
    for (char ch : key) {
        hash = (hash * 31 + ch) % size;
    }
    return hash;
}

void HashTable::put(string key, string value) {
    int index = hashFunction(key);
    NodeHT* current = table[index];

    // проверяем, есть ли уже такой ключ
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value; // обновляем существующее значение
            return;
        }
        current = current->next;
    }

    // если ключа еще нет, добавляем новый узел в начало списка
    NodeHT* newNode = new NodeHT(key, value);
    newNode->next = table[index];
    table[index] = newNode;
}

string HashTable::get(string key) {
    int index = hashFunction(key);
    NodeHT* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return "Ключ не найден!"; // или же можно бросить исключение, если ключ не найден
}

bool HashTable::remove(string key) {
    int index = hashFunction(key);
    NodeHT* current = table[index];
    NodeHT* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            else {
                table[index] = current->next;
            }
            cout << current->value;
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false; // ключ не найден
}