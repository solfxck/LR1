#include <iostream>
#pragma once

using namespace std;

struct Node {
    string data; // данные, хранящиеся в узле
    Node* next;  // указатель на следующий узел в списке
    Node* prev;  // указатель на предыдущий узел в списке

    // конструктор для создания нового узла
    // принимает значение данных, указатель на следующий узел и указатель на предыдущий узел
    Node(const string& value, Node* nextNode = nullptr, Node* prevNode = nullptr)
        : data(value), next(nextNode), prev(prevNode) {
    }
};

// Node для хеш-таблицы
struct NodeHT {
    string key;   // ключ
    string value; // Значение, связанное с ключом
    NodeHT* next; // указатель на следующий узел в цепочке (для разрешения коллизий)

    // конструктор для создания нового узла хеш-таблицы
    // принимает ключ, значение и указатель на следующий узел в цепочке
    NodeHT(const string& k, const string& v, NodeHT* nextNode = nullptr)
        : key(k), value(v), next(nextNode) {
    }
};

// Node для АВЛ-дерева
struct NodeAVL {
    int key; // ключ
    NodeAVL* left; // указатель на левое поддерево
    NodeAVL* right; // указатель на правое поддерево
    int height; // высота поддерева с корнем в данном узле

    // конструктор для создания нового узла АВЛ-дерева
    // принимает ключ и инициализирует указатели на левое и правое поддеревья, а также высоту
    NodeAVL(int key) : key(key), left(nullptr), right(nullptr), height(1) {}
};

// объявление структуры Queue
struct Queue {
    Node* head;
    Node* tail;
    Queue() {
        head = nullptr;
        tail = nullptr;
    }
    void push(string value); //добавление
    void pop(); //удаление
    void display(); //вывод на экран
};

// объявление структуры Stack
struct Stack {
    Node* top;
    Stack() {
        top = nullptr;
    }
    void push(string value);
    void pop();
    void display();
};

// объявление структуры Array
struct Array {
    Node* head;
    int size;
    int capacity;

    Array(int initialCapacity = 10);
    void push(int index, string value);
    void pushEnd(string value);
    string get(int index);
    void pop(int index);
    void replace(int index, string value);
    int length();
    void display();
};

// объявление структуры List
struct List {
    Node* head;
    Node* tail;
    int size;

    List();
    void pushHead(string value);
    void pushTail(string value);
    void popHead();
    void popTail();
    bool popValue(string value);
    bool search(string value);
    void display();
};

// объявление структуры DubleList
struct DubleList {
    Node* head;
    Node* tail;
    int size;

    DubleList();
    void pushHead(string value);
    void pushTail(string value);
    void popHead();
    void popTail();
    bool popValue(string value);
    bool search(string value);
    void display();
};

// объявление структуры HashTable
struct HashTable {
    static const int size = 10; // Размер хеш-таблицы
    NodeHT* table[size]; // Массив указателей на Node

    HashTable();
    int hashFunction(const string& key);
    int hashFunction2(const string& key);
    void insert(const string& key, const string& value);
    string get(const string& key);
    void remove(const string& key);
    void display();
};

// объявление структуры AVL
struct AVL {
    NodeAVL* root;

    AVL() : root(nullptr) {}
    int height(NodeAVL* node);
    int balanceFactor(NodeAVL* node);
    NodeAVL* rightRotate(NodeAVL* y);
    NodeAVL* leftRotate(NodeAVL* x);
    NodeAVL* insert(NodeAVL* node, int key);
    NodeAVL* minValueNode(NodeAVL* node);
    NodeAVL* deleteNode(NodeAVL* root, int key);
    NodeAVL* search(NodeAVL* node, int key);
    void preOrder(NodeAVL* node);
    void saveToFile(NodeAVL* node, ofstream& outputFile);
    void insert(int key);
    void remove(int key);
    bool search(int key);
    void display();
};
