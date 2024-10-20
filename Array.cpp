#include "header.h"
#include <iostream>

using namespace std;

// пустой массив
Array::Array(int initialCapacity) {
    head = nullptr;
    size = 0;
    capacity = initialCapacity; // максимально допустимое количество элементов
}

// Сложность: O(n)
void Array::push(int index, string value) {
    if (index < 0 || index > size || size >= capacity) { // проверяем корректность индекса и достаточность емкости
        cout << "Невозможно добавить элемент. Ошибка индекса или превышен максимальный размер." << endl;
        return;
    }

    Node* newNode = new Node(value); // создаем новый узел с переданным значением
    if (index == 0) { // если элемент вставляется в начало списка
        newNode->next = head; // следующий элемент нового узла указывает на текущую голову списка
        head = newNode; // голова обновляется на новый узел
    }
    else {
        Node* current = head; // начинаем с головы списка
        for (int i = 0; i < index - 1; i++) { // проходим до узла перед нужным индексом
            current = current->next; // переходим к следующему узлу
        }
        newNode->next = current->next; // новый узел указывает на следующий узел
        current->next = newNode; // предыдущий узел указывает на новый узел
    }
    size++;
}

// Сложность: O(n)
void Array::pushEnd(string value) {
    push(size, value);  // просто вызываем push, передавая размер списка как индекс для вставки в конец
}

// Сложность: O(n)
string Array::get(int index) {
    if (index < 0 || index >= size) { // проверка на корректность индекса
        return "Неверный индекс"; // возвращаем пустую строку
    }
    Node* current = head; // начинаем с головы
    for (int i = 0; i < index; i++) { // движемся к узлу с нужным индексом
        current = current->next;
    }
    return current->data; // возвращаем данные узла на нужной позиции
}

// Сложность: O(n)
void Array::pop(int index) {
    if (index < 0 || index >= size) {  // проверка на корректность индекса
        cout << "Неверный индекс!" << endl;
        return;
    }

    Node* toDelete = nullptr;  // указатель на удаляемый узел
    if (index == 0) {  // если удаляем первый элемент
        toDelete = head;  // запоминаем текущую голову
        head = head->next;  // обновляем голову
    }
    else {
        Node* current = head;  // начинаем с головы
        for (int i = 0; i < index - 1; i++) {  // движемся к узлу перед индексом
            current = current->next;
        }
        toDelete = current->next;  // узел для удаления
        current->next = toDelete->next;  // обходим удаляемый узел
    }
    delete toDelete;  // освобождаем память удаленного узла
    size--;  // уменьшаем размер списка
}

// Сложность: O(n)
void Array::replace(int index, string value) {
    if (index < 0 || index >= size) {  // проверка индекса
        cout << "Неверный индекс!" << endl;
        return;
    }

    Node* current = head;  // начинаем с головы

    for (int i = 0; i < index; i++) {  // движемся к нужному индексу
        current = current->next;
    }
    current->data = value;  // заменяем данные узла
}

// Сложность: O(1)
int Array::length() {
    return size;
}

// Сложность: O(n)
void Array::display() {
    if (head == nullptr) {
        cout << "Массив пуст!" << endl;
        return;
    }

    Node* current = head;  // начинаем с головы
    while (current) {  // пока есть элементы
        cout << current->data << " ";
        current = current->next;  // переходим к следующему узлу
    }
    cout << endl;
}