package main

import (
	"fmt"
	"os"
)

type AVL struct {
	root *NodeAVL
}

func (avl *AVL) height(node *NodeAVL) int {
	if node == nil {
		return 0
	}
	return node.height
}

func (avl *AVL) balanceFactor(node *NodeAVL) int {
	if node == nil {
		return 0
	}
	return avl.height(node.left) - avl.height(node.right)
}

func (avl *AVL) rightRotate(y *NodeAVL) *NodeAVL {
	x := y.left
	T2 := x.right

	x.right = y
	y.left = T2

	y.height = max(avl.height(y.left), avl.height(y.right)) + 1
	x.height = max(avl.height(x.left), avl.height(x.right)) + 1

	return x
}

func (avl *AVL) leftRotate(x *NodeAVL) *NodeAVL {
	y := x.right
	T2 := y.left

	y.left = x
	x.right = T2

	x.height = max(avl.height(x.left), avl.height(x.right)) + 1
	y.height = max(avl.height(y.left), avl.height(y.right)) + 1

	return y
}

func (avl *AVL) insert(node *NodeAVL, key int) *NodeAVL {
	if node == nil {
		return &NodeAVL{key: key, height: 1}
	}

	if key < node.key {
		node.left = avl.insert(node.left, key)
	} else if key > node.key {
		node.right = avl.insert(node.right, key)
	} else {
		return node
	}

	node.height = 1 + max(avl.height(node.left), avl.height(node.right))

	balance := avl.balanceFactor(node)

	if balance > 1 && key < node.left.key {
		return avl.rightRotate(node)
	}

	if balance < -1 && key > node.right.key {
		return avl.leftRotate(node)
	}

	if balance > 1 && key > node.left.key {
		node.left = avl.leftRotate(node.left)
		return avl.rightRotate(node)
	}

	if balance < -1 && key < node.right.key {
		node.right = avl.rightRotate(node.right)
		return avl.leftRotate(node)
	}

	return node
}

func (avl *AVL) minValueNode(node *NodeAVL) *NodeAVL {
	current := node
	for current.left != nil {
		current = current.left
	}
	return current
}

func (avl *AVL) deleteNode(root *NodeAVL, key int) *NodeAVL {
	if root == nil {
		return root
	}

	if key < root.key {
		root.left = avl.deleteNode(root.left, key)
	} else if key > root.key {
		root.right = avl.deleteNode(root.right, key)
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
			temp := avl.minValueNode(root.right)
			root.key = temp.key
			root.right = avl.deleteNode(root.right, temp.key)
		}
	}

	if root == nil {
		return root
	}

	root.height = 1 + max(avl.height(root.left), avl.height(root.right))

	balance := avl.balanceFactor(root)

	if balance > 1 && avl.balanceFactor(root.left) >= 0 {
		return avl.rightRotate(root)
	}

	if balance > 1 && avl.balanceFactor(root.left) < 0 {
		root.left = avl.leftRotate(root.left)
		return avl.rightRotate(root)
	}

	if balance < -1 && avl.balanceFactor(root.right) <= 0 {
		return avl.leftRotate(root)
	}

	if balance < -1 && avl.balanceFactor(root.right) > 0 {
		root.right = avl.rightRotate(root.right)
		return avl.leftRotate(root)
	}

	return root
}

func (avl *AVL) search(node *NodeAVL, key int) *NodeAVL {
	if node == nil || node.key == key {
		return node
	}

	if key < node.key {
		return avl.search(node.left, key)
	} else {
		return avl.search(node.right, key)
	}
}

func (avl *AVL) preOrder(node *NodeAVL) {
	if node != nil {
		fmt.Print(node.key, " ")
		avl.preOrder(node.left)
		avl.preOrder(node.right)
	}
}

func (avl *AVL) saveToFile(node *NodeAVL, outputFile *os.File) {
	if node == nil {
		return
	}

	fmt.Fprintln(outputFile, node.key)
	avl.saveToFile(node.left, outputFile)
	avl.saveToFile(node.right, outputFile)
}

func (avl *AVL) Insert(key int) {
	avl.root = avl.insert(avl.root, key)
}

func (avl *AVL) Remove(key int) {
	avl.root = avl.deleteNode(avl.root, key)
}

func (avl *AVL) Search(key int) bool {
	return avl.search(avl.root, key) != nil
}

func (avl *AVL) Display() {
	avl.preOrder(avl.root)
	fmt.Println()
}
