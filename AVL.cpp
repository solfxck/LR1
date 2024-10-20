#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;

// получения высоты узла
// Сложность: O(1)
int AVL::height(NodeAVL* node) {
    if (node == nullptr) return 0; // если узел пустой, высота равна 0
    return node->height; // иначе возвращаем высоту узла
}

// нужен ли баланс? (высота правого и левого поддерева не должна превышать 1)
// Сложность: O(1)
int AVL::balanceFactor(NodeAVL* node) {
    if (node == nullptr) return 0; // если узел пустой, баланс-фактор равен 0
    return height(node->left) - height(node->right); // иначе возвращаем разницу высот левого и правого поддеревьев
}

// правый поворот
// Сложность: O(1)
NodeAVL* AVL::rightRotate(NodeAVL* y) {
    NodeAVL* x = y->left; // x - левый потомок y
    NodeAVL* T2 = x->right; // T2 - правый потомок x

    x->right = y; // делаем y правым потомком x
    y->left = T2; // делаем T2 левым потомком y

    // обновляем высоты y и x
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // новый корень поддерева
}

// левый поворот
// Сложность: O(1)
NodeAVL* AVL::leftRotate(NodeAVL* x) {
    NodeAVL* y = x->right; // y - правый потомок x
    NodeAVL* T2 = y->left; // T2 - левый потомок y

    y->left = x; // делаем x левым потомком y
    x->right = T2; // делаем T2 правым потомком x

    // обновляем высоты x и y
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // новый корень поддерева
}

// вставка узла в АВЛ-дерево
// Сложность: O(log n)
NodeAVL* AVL::insert(NodeAVL* node, int key) {
    // если текущий узел пустой, создаем новый узел с переданным ключом
    if (node == nullptr) return new NodeAVL(key);

    // если ключ меньше ключа текущего узла, рекурсивно вставляем в левое поддерево
    if (key < node->key)
        node->left = insert(node->left, key);
    // если ключ больше ключа текущего узла, рекурсивно вставляем в правое поддерево
    else if (key > node->key)
        node->right = insert(node->right, key);
    // если ключ уже существует, возвращаем текущий узел (дубликаты не допускаются)
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right)); // обновляем высоту текущего узла

    // вычисляем баланс-фактор текущего узла
    int balance = balanceFactor(node);

    // левый-левый случай: баланс-фактор > 1 и ключ меньше ключа левого потомка
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // правый-правый случай: баланс-фактор < -1 и ключ больше ключа правого потомка
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // левый-правый случай: баланс-фактор > 1 и ключ больше ключа левого потомка
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // правый-левый случай: баланс-фактор < -1 и ключ меньше ключа правого потомка
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // возвращаем корень поддерева
}

// поиска узла с минимальным значением в поддереве
// Сложность: O(log n)
NodeAVL* AVL::minValueNode(NodeAVL* node) {
    NodeAVL* current = node;
    while (current->left != nullptr) // идем по левому поддереву до самого левого узла
        current = current->left;
    return current;
}

// удаление узла из АВЛ-дерева
// Сложность: O(log n)
NodeAVL* AVL::deleteNode(NodeAVL* root, int key) {
    if (root == nullptr) return root; // если дерево пустое, возвращаем его

    // если ключ меньше ключа текущего узла, рекурсивно удаляем в левом поддереве
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    // если ключ больше ключа текущего узла, рекурсивно удаляем в правом поддереве
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    // если ключ совпадает с ключом текущего узла, удаляем текущий узел
    else {
        // если у текущего узла нет одного из потомков или оба потомка отсутствуют
        if (root->left == nullptr || root->right == nullptr) {
            // выбираем непустого потомка или nullptr, если оба потомка отсутствуют
            NodeAVL* temp = root->left ? root->left : root->right;

            // если непустой потомок отсутствует, удаляем текущий узел
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            // если есть непустой потомок, копируем его данные в текущий узел
            else
                *root = *temp;

            delete temp; // освобождаем память удаляемого узла
        }
        // если у текущего узла есть оба потомка
        else {
            NodeAVL* temp = minValueNode(root->right); // находим узел с минимальным ключом в правом поддереве
            root->key = temp->key; // копируем ключ минимального узла в текущий узел
            root->right = deleteNode(root->right, temp->key); // рекурсивно удаляем минимальный узел из правого поддерева
        }
    }

    // если дерево стало пустым после удаления, возвращаем его
    if (root == nullptr) return root;

    // обновляем высоту текущего узла
    root->height = 1 + max(height(root->left), height(root->right));

    // вычисляем баланс-фактор текущего узла
    int balance = balanceFactor(root);

    // левый-левый случай: баланс-фактор > 1 и баланс-фактор левого поддерева >= 0
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    // левый-правый случай: баланс-фактор > 1 и баланс-фактор левого поддерева < 0
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // правый-правый случай: баланс-фактор < -1 и баланс-фактор правого поддерева <= 0
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    // правый-левый случай: баланс-фактор < -1 и баланс-фактор правого поддерева > 0
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // возвращаем корень поддерева
}

// поиска узла
// Сложность: O(log n)
NodeAVL* AVL::search(NodeAVL* node, int key) {
    if (node == nullptr || node->key == key) return node; // если узел пустой или ключ найден, возвращаем узел

    if (key < node->key)
        return search(node->left, key); // если ключ меньше, ищем в левом поддереве
    else
        return search(node->right, key); // если ключ больше, ищем в правом поддереве
}

// функция для обхода дерева в прямом порядке
// Сложность: O(n)
void AVL::preOrder(NodeAVL* node) {
    if (node != nullptr) {
        cout << node->key << " "; // выводим ключ текущего узла
        preOrder(node->left); // рекурсивно обходим левое поддерево
        preOrder(node->right); // рекурсивно обходим правое поддерево
    }
}

// сохранения дерева в файл
void AVL::saveToFile(NodeAVL* node, ofstream& outputFile) {
    if (node == nullptr) return;

    outputFile << node->key << endl; // записываем ключ текущего узла

    // рекурсивно записываем левое и правое поддеревья
    saveToFile(node->left, outputFile);
    saveToFile(node->right, outputFile);
}

// Функция для вставки значения(ключа)
// Сложность: O(log n)
void AVL::insert(int key) {
    root = insert(root, key);
}

// удаление значения
// Сложность: O(log n)
void AVL::remove(int key) {
    root = deleteNode(root, key);
}

// поиск значения
// Сложность: O(log n)
bool AVL::search(int key) {
    return search(root, key) != nullptr;
}

// Сложность: O(n)
void AVL::display() {
    preOrder(root);
    cout << endl;
}