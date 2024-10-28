package main

type Node struct {
	data string
	next *Node
	prev *Node
}

type Node1 struct {
	data string
	next *Node1
}

type NodeHT struct {
	key   string
	value string
	next  *NodeHT
}

type NodeAVL struct {
	key    int
	left   *NodeAVL
	right  *NodeAVL
	height int
}
