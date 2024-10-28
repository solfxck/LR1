package main

import (
	"fmt"
)

type HashTable struct {
	table []*NodeHT
	size  int
	count int
}

func NewHashTable(initialSize int) *HashTable {
	return &HashTable{table: make([]*NodeHT, initialSize), size: initialSize, count: 0}
}

func (ht *HashTable) hashFunction(key string) int {
	hash := 0
	for _, c := range key {
		hash += int(c)
	}
	return hash % ht.size
}

func (ht *HashTable) Insert(key, value string) {
	index := ht.hashFunction(key)
	current := ht.table[index]
	for current != nil {
		if current.key == key {
			current.value = value
			return
		}
		current = current.next
	}
	node := &NodeHT{key: key, value: value, next: ht.table[index]}
	ht.table[index] = node
	ht.count++
}

func (ht *HashTable) Get(key string) string {
	index := ht.hashFunction(key)
	current := ht.table[index]
	for current != nil {
		if current.key == key {
			return current.value
		}
		current = current.next
	}
	return "Ключ не найден!"
}

func (ht *HashTable) Remove(key string) {
	index := ht.hashFunction(key)
	current := ht.table[index]
	var prev *NodeHT
	for current != nil {
		if current.key == key {
			if prev == nil {
				ht.table[index] = current.next
			} else {
				prev.next = current.next
			}
			ht.count--
			return
		}
		prev = current
		current = current.next
	}
}

func (ht *HashTable) Display() {
	for i := 0; i < ht.size; i++ {
		fmt.Printf("[%d]: ", i)
		current := ht.table[i]
		for current != nil {
			fmt.Printf("(%s, %s) ", current.key, current.value)
			current = current.next
		}
		fmt.Println()
	}
}
