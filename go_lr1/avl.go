package main

import (
    "fmt"
    "os"
    "strconv"
)

// AVL представляет АВЛ
// AVL представляет АВЛ-дерево
type AVL struct {
    root *NodeAVL
}

// height возвращает высоту узла
func height(node *NodeAVL) int {
    if node == nil {
        return 0
    }
    return node.height
}

// balanceFactor вычисляет баланс-фактор узла
func balanceFactor(node *NodeAVL) int {
    if node == nil {
        return 0
    }
    return height(node.left) - height(node.right)
}

// rightRotate выполняет правый поворот
func rightRotate(y *NodeAVL) *NodeAVL {
    x := y.left
    T2 := x.right

    x.right = y
    y.left = T2

    y.height = max(height(y.left), height(y.right)) + 1
    x.height = max(height(x.left), height(x.right)) + 1

    return x
}

// leftRotate выполняет левый поворот
func leftRotate(x *NodeAVL) *NodeAVL {
    y := x.right
    T2 := y.left

    y.left = x
    x.right = T2

    x.height = max(height(x.left), height(x.right)) + 1
    y.height = max(height(y.left), height(y.right)) + 1

    return y
}

// insert вставляет узел в АВЛ-дерево
func insert(node *NodeAVL, key int) *NodeAVL {
    if node == nil {
        return &NodeAVL{key: key, height: 1}
    }

    if key < node.key {
        node.left = insert(node.left, key)
    } else if key > node.key {
        node.right = insert(node.right, key)
    } else {
        return node // дубликаты не допускаются
    }

    node.height = 1 + max(height(node.left), height(node.right))

    balance := balanceFactor(node)

    if balance > 1 && key < node.left.key {
        return rightRotate(node)
    }

    if balance < -1 && key > node.right.key {
        return leftRotate(node)
    }

    if balance > 1 && key > node.left.key {
        node.left = leftRotate(node.left)
        return rightRotate(node)
    }

    if balance < -1 && key < node.right.key {
        node.right = rightRotate(node.right)
        return leftRotate(node)
    }

    return node
}

// minValueNode находит узел с минимальным значением в поддереве
func minValueNode(node *NodeAVL) *NodeAVL {
    current := node
    for current.left != nil {
        current = current.left
    }
    return current
}

// deleteNode удаляет узел из АВЛ-дерева
func deleteNode(root *NodeAVL, key int) *NodeAVL {
    if root == nil {
        return root
    }

    if key < root.key {
        root.left = deleteNode(root.left, key)
    } else if key > root.key {
        root.right = deleteNode(root.right, key)
    } else {
        if root.left == nil || root.right == nil {
            var temp *NodeAVL
            if root.left != nil {
                temp = root.left
            } else {
                temp = root.right
            }

            if temp == nil {
                temp = root
                root = nil
            } else {
                *root = *temp
            }
            temp = nil
        } else {
            temp := minValueNode(root.right)
            root.key = temp.key
            root.right = deleteNode(root.right, temp.key)
        }
    }

    if root == nil {
        return root
    }

    root.height = 1 + max(height(root.left), height(root.right))

    balance := balanceFactor(root)

    if balance > 1 && balanceFactor(root.left) >= 0 {
        return rightRotate(root)
    }

    if balance > 1 && balanceFactor(root.left) < 0 {
        root.left = leftRotate(root.left)
        return rightRotate(root)
    }

    if balance < -1 && balanceFactor(root.right) <= 0 {
        return leftRotate(root)
    }

    if balance < -1 && balanceFactor(root.right) > 0 {
        root.right = rightRotate(root.right)
        return leftRotate(root)
    }

    return root
}

// search ищет узел в АВЛ-дереве
func search(node *NodeAVL, key int) *NodeAVL {
    if node == nil || node.key == key {
        return node
    }

    if key < node.key {
        return search(node.left, key)
    }

    return search(node.right, key)
}

// preOrder выполняет обход дерева в прямом порядке
func preOrder(node *NodeAVL) {
    if node != nil {
        fmt.Print(node.key, " ")
        preOrder(node.left)
        preOrder(node.right)
    }
}

// saveToFile сохраняет дерево в файл
func saveToFile(node *NodeAVL, file *os.File) {
    if node == nil {
        return
    }

    file.WriteString(strconv.Itoa(node.key) + "\n")
    saveToFile(node.left, file)
    saveToFile(node.right, file)
}

// Insert добавляет элемент в АВЛ-дерево
func (avl *AVL) Insert(key int) {
    avl.root = insert(avl.root, key)
}

// Remove удаляет элемент из АВЛ-дерева
func (avl *AVL) Remove(key int) {
    avl.root = deleteNode(avl.root, key)
}

// Search ищет элемент в АВЛ-дереве
func (avl *AVL) Search(key int) bool {
    return search(avl.root, key) != nil
}

// Display выводит дерево в прямом порядке
func (avl *AVL) Display() {
    preOrder(avl.root)
    fmt.Println()
}

// SaveToFile сохраняет дерево в файл
func (avl *AVL) SaveToFile(filename string) {
    file, err := os.Create(filename)
    if err != nil {
        fmt.Println("Ошибка при создании файла:", err)
        return
    }
    defer file.Close()

    saveToFile(avl.root, file)
}