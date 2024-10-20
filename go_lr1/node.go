package main

// Node представляет узел двусвязного списка
type Node struct {
    data string
    next *Node
    prev *Node
}

// NodeHT представляет узел хеш-таблицы
type NodeHT struct {
    key   string
    value string
    next  *NodeHT
}

// NodeAVL представляет узел АВЛ-дерева
type NodeAVL struct {
    key    int
    left   *NodeAVL
    right  *NodeAVL
    height int
}