#include "header.h"
#include <iostream>

using namespace std;

// пустой двусвязный список
DubleList::DubleList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Сложность: O(1)
void DubleList::pushHead(string value) {
    Node* newNode = new Node(value); // создаем новый узел с переданным значением
    if (head == nullptr) { // если список пуст
        head = tail = newNode; // новый узел становится и началом, и концом
    }
    else {  // если список не пуст
        newNode->next = head; // следующий элемент нового узла указывает на старую голову
        head->prev = newNode; // старая голова теперь указывает назад на новый узел
        head = newNode; // новый узел становится головой списка
    }
    size++;
}

// Сложность: O(1)
void DubleList::pushTail(string value) {
    Node* newNode = new Node(value); // создаем новый узел с переданным значением
    if (tail == nullptr) { // если список пуст
        head = tail = newNode; // новый узел становится и началом, и концом
    }
    else {  // если список не пуст
        tail->next = newNode; // следующий элемент старого хвоста указывает на новый узел
        newNode->prev = tail; // новый узел указывает назад на старый хвост
        tail = newNode; // новый узел становится хвостом списка
    }
    size++;
}

// Сложность: O(1)
void DubleList::popHead() {
    if (head == nullptr) { // если список пуст
        cout << "Список пуст!" << endl;
        return;
    }
    Node* toDelete = head; // сохраняем указатель на удаляемую голову
    head = head->next; // смещаем голову на следующий элемент
    if (head != nullptr) { // если список не стал пустым
        head->prev = nullptr; // новый первый элемент теперь не имеет предыдущего
    }
    else {
        tail = nullptr; // если список стал пустым, обнуляем хвост
    }
    delete toDelete; // освобождаем память удаленной головы
    size--;
}

// Сложность: O(1)
void DubleList::popTail() {
    if (head == nullptr) { // если список пуст
        cout << "Список пуст!" << endl;
        return;
    }
    if (head == tail) { // если в списке только один элемент
        delete tail; // удаляем единственный элемент
        head = tail = nullptr; // обнуляем указатели на голову и хвост
    }
    else { // если элементов несколько
        Node* toDelete = tail;  // сохраняем указатель на удаляемый хвост
        tail = tail->prev;  // смещаем хвост на предыдущий элемент
        tail->next = nullptr;  // новый хвост не указывает на следующий элемент
        delete toDelete;  // освобождаем память удаленного хвоста
    }
    size--;
}

// Сложность: O(n)
bool DubleList::popValue(string value) {
    if (head == nullptr) {
        cout << "Список пуст!" << endl;
        return false;
    }

    Node* current = head;  // начинаем поиск с головы списка

    while (current != nullptr && current->data != value) {  // пока не найден элемент с нужным значением
        current = current->next;  // переходим к следующему узлу
    }

    if (current == nullptr) return false;  // если элемент не найден, возвращаем false

    // если элемент найден, удаляем его
    if (current->prev) {
        current->prev->next = current->next;  // если у текущего узла есть предыдущий, обновляем его связь
    }
    else {
        head = current->next;  // если это первый элемент, обновляем голову
    }

    if (current->next) {
        current->next->prev = current->prev;  // если у текущего узла есть следующий, обновляем его связь
    }
    else {
        tail = current->prev;  // если это последний элемент, обновляем хвост
    }

    delete current;  // освобождаем память удаленного узла
    size--;
    return true;
}

// Сложность: O(n)
bool DubleList::search(string value) {
    Node* current = head;  // начинаем поиск с головы списка
    while (current != nullptr) {  // пока не дошли до конца списка
        if (current->data == value) return true;  // если нашли элемент
        current = current->next;  // переходим к следующему узлу
    }
    return false;  // если элемент не найден
}

// Сложность: O(n)
void DubleList::display() {
    if (head == nullptr) {
        cout << "Список пуст!" << endl;
        return;
    }

    Node* current = head;  // начинаем вывод с головы списка
    while (current != nullptr) {  // пока не дошли до конца списка
        cout << current->data << " ";
        current = current->next;  // переходим к следующему узлу
    }
    cout << endl;
}