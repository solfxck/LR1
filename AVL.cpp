#include "header.h"
#include "node.h"
#include <iostream>
#include <fstream>

using namespace std;

int AVL::height(NodeAVL* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int AVL::balanceFactor(NodeAVL* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

NodeAVL* AVL::rightRotate(NodeAVL* y) {
    NodeAVL* x = y->left;
    NodeAVL* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

NodeAVL* AVL::leftRotate(NodeAVL* x) {
    NodeAVL* y = x->right;
    NodeAVL* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

NodeAVL* AVL::insert(NodeAVL* node, int key) {
    if (node == nullptr) return new NodeAVL(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Дубликаты не допускаются

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Левый-левый случай
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Правый-правый случай
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Левый-правый случай
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Правый-левый случай
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

NodeAVL* AVL::minValueNode(NodeAVL* node) {
    NodeAVL* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

NodeAVL* AVL::deleteNode(NodeAVL* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            NodeAVL* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;

            delete temp;
        }
        else {
            NodeAVL* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = balanceFactor(root);

    // Левый-левый случай
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Левый-правый случай
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Правый-правый случай
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Правый-левый случай
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

NodeAVL* AVL::search(NodeAVL* node, int key) {
    if (node == nullptr || node->key == key) return node;

    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

void AVL::inOrder(NodeAVL* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }
}

void AVL::insert(int key) {
    root = insert(root, key);
}

void AVL::remove(int key) {
    root = deleteNode(root, key);
}

bool AVL::search(int key) {
    return search(root, key) != nullptr;
}

void AVL::display() {
    inOrder(root);
    cout << endl;
}