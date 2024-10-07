#include "header.h"
#include "node.h"

// Реализация метода добавления элемента в стек
void Stack::push(std::string value) {
    Node* node = new Node{ value, top }; // Устанавливаем новый узел поверх стека
    top = node;
}

// Реализация метода удаления элемента из стека
void Stack::pop() {
    if (top == nullptr) {
        cout << "Стек пуст!" << endl;
    }
    else {
        Node* temp = top;
        top = top->next; // Убираем верхний элемент
        cout << "Удаленный элемент: " << temp->data << endl;
        delete temp;
    }
}

// Реализация метода вывода элементов стека
void Stack::display() {
    if (top == nullptr) {
        cout << "Стек пуст!" << endl;
    }
    else {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}