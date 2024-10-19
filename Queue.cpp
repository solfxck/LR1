#include "header.h"
#include "node.h"

// Сложность: O(1)
void Queue::push(string value) {
    // создаем новый узел с заданным значением и указателем на следующий элемент, равным nullptr
    Node* node = new Node{ value, nullptr };
    
    // проверяем, пуста ли очередь
    if (head == nullptr) {
        // если пустая, то и голова, и хвост очереди теперь указывают на новый узел
        head = node;
        tail = node;
    } 
    else {
        // если не пустая, то добавляем новый узел в конец очереди
        tail->next = node; // устанавливаем указатель текущего хвоста на новый узел
        tail = node; // обновляем указатель хвоста
    }
}

// Сложность: O(1)
void Queue::pop() {
    // проверяем, пуста ли очередь
    if (head == nullptr) {
        cout << "Очередь пуста!" << endl;
    } 
    else {
        Node* temp = head; // временно сохраняем указатель на текущую голову (первый элемент)
        head = head->next; // перемещаем указатель головы на следующий элемент в очереди
        cout << "Удаленный элемент: " << temp->data << endl;
        delete temp; // освобождаем память, занятую удаляемым элементом

        // если после удаления очередь стала пустой
        if (head == nullptr) {
            tail = nullptr; // устанавливаем хвост также равным nullptr
        }
    }
}

// Сложность: O(n)
void Queue::display() {
    // проверяем, пуста ли очередь
    if (head == nullptr) {
        cout << "Очередь пуста!" << endl;
    }
    else {
        Node* current = head; // для итерации по элементам очереди

        // пока не достигнут конец очереди
        while (current != nullptr) {
            cout << current->data << " ";
            // перемещаемся к следующему элементу
            current = current->next;
        }
        cout << endl;
    }
}