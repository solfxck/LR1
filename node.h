#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;

    Node(const string& value, Node* nextNode = nullptr, Node* prevNode = nullptr)
        : data(value), next(nextNode), prev(prevNode) {
    }
};

struct NodeHT {
    string key;
    string value;
    NodeHT* next;

    NodeHT(string key, string value) : key(key), value(value), next(nullptr) {}
};

struct NodeAVL {
    int key;
    NodeAVL* left;
    NodeAVL* right;
    int height;

    NodeAVL(int key) : key(key), left(nullptr), right(nullptr), height(1) {}
};