#include "header.h"
#include "node.h"
#include <iostream>

using namespace std;

Array::Array(int initialCapacity) {
    head = nullptr;
    size = 0;
    capacity = initialCapacity;
}

void Array::push(int index, string value) {
    if (index < 0 || index > size || size >= capacity) {
        cout << "Невозможно добавить элемент. Ошибка индекса или превышен максимальный размер." << endl;
        return;
    }

    Node* newNode = new Node(value);
    if (index == 0) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
}

void Array::pushEnd(string value) {
    push(size, value);
}

string Array::get(int index) {
    if (index < 0 || index >= size) {
        cout << "Неверный индекс!" << endl;
        return "";
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void Array::pop(int index) {
    if (index < 0 || index >= size) {
        cout << "Неверный индекс!" << endl;
        return;
    }

    Node* toDelete = nullptr;
    if (index == 0) {
        toDelete = head;
        head = head->next;
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        toDelete = current->next;
        current->next = toDelete->next;
    }
    delete toDelete;
    size--;
}

void Array::replace(int index, string value) {
    if (index < 0 || index >= size) {
        cout << "Неверный индекс!" << endl;
        return;
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = value;
}

int Array::length() {
    return size;
}

void Array::display() {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
