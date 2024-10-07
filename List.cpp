#include "header.h"
#include "node.h"
#include <iostream>

using namespace std;

List::List() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void List::pushHead(string value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

void List::pushTail(string value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void List::popHead() {
    if (head == nullptr) {
        cout << "Список пуст!" << endl;
        return;
    }
    Node* toDelete = head;
    head = head->next;
    if (head == nullptr) tail = nullptr; // если удаляется единственный элемент
    delete toDelete;
    size--;
}

void List::popTail() {
    if (head == nullptr) {
        cout << "Список пуст!" << endl;
        return;
    }
    if (head == tail) { // если один элемент
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    size--;
}

bool List::popValue(string value) {
    if (head == nullptr) {
        cout << "Список пуст!" << endl;
        return false;
    }

    if (head->data == value) {
        popHead();
        return true;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) { // элемент не найден {
        cout << "Список пуст!" << endl;
        return false;
    }

    Node* toDelete = current->next;
    current->next = toDelete->next;
    if (toDelete == tail) tail = current; // если удаляем последний элемент
    delete toDelete;
    size--;
    return true;
}

bool List::search(string value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

void List::display() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}