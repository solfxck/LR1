#include "header.h"
#include "node.h"
#include <iostream>

using namespace std;

DubleList::DubleList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void DubleList::pushHead(string value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void DubleList::pushTail(string value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void DubleList::popHead() {
    if (head == nullptr) {
        cout << "Список пуст!" << endl;
        return;
    }
    Node* toDelete = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;  // если удаляется единственный элемент
    }
    delete toDelete;
    size--;
}

void DubleList::popTail() {
    if (head == nullptr) {
        cout << "Список пуст!" << endl;
        return;
    }
    if (head == tail) {  // если один элемент
        delete tail;
        head = tail = nullptr;
    }
    else {
        Node* toDelete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete toDelete;
    }
    size--;
}

bool DubleList::popValue(string value) {
    if (head == nullptr) {
        cout << "Список пуст!" << endl;
        return false;
    }

    Node* current = head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    if (current == nullptr) return false; // элемент не найден

    if (current->prev) {
        current->prev->next = current->next;
    }
    else {
        head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    }
    else {
        tail = current->prev;
    }

    delete current;
    size--;
    return true;
}

bool DubleList::search(string value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

void DubleList::display() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}