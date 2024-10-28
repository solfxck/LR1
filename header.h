#include <iostream>
#pragma once

using namespace std;

// определение структуры Node (двусвязный список)
struct Node {
    string data;
    Node* next;
    Node* prev;

    Node(const string& value, Node* nextNode = nullptr, Node* prevNode = nullptr)
        : data(value), next(nextNode), prev(prevNode) {}
};

// определение структуры Node1 (спиок, очередь, стек)
struct Node1 {
    string data; // данные узла
    Node1* next; // указатель на следующий узел

    // конструктор для узла
    Node1(const string& value) : data(value), next(nullptr) {}
};

// структура NodeHT представляет узел в хеш-таблице
struct NodeHT {
    string key; // ключ, по которому хранится значение
    string value; // значение, связанное с ключом
    NodeHT* next; // указатель на следующий узел в связанном списке (для решения коллизий)

    // конструктор для создания нового узла хеш-таблицы
    // принимает ключ и значение
    NodeHT(const string& k, const string& v) : key(k), value(v), next(nullptr) {}
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
    Node1* head;
    Node1* tail;
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
    Node1* top;
    Stack() {
        top = nullptr;
    }
    void push(string value);
    void pop();
    void display();
};

// объявление структуры Array
struct Array {
    string* data;
    int size;
    int capacity;

    Array();
    void pushEnd(string value);
    void push(int index, string value);
    string get(int index);
    void pop(int index);
    void replace(int index, string value);
    int length();
    void display();
};

// объявление структуры List
struct List {
    Node1* head;
    Node1* tail;
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
    NodeHT** table; // массив указателей на узлы хеш-таблицы
    int size; // размер хеш-таблицы
    int count; // количество элементов в хеш-таблице

    HashTable(int initialSize = 10);
    int hash_function(const string& str);
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