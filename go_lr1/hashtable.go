package main

import (
    "fmt"
    "hash/fnv"
)

// HashTable представляет хеш-таблицу
type HashTable struct {
    table []*NodeHT
    size  int
}

// NewHashTable создает новую хеш-таблицу
func NewHashTable(size int) *HashTable {
    return &HashTable{table: make([]*NodeHT, size), size: size}
}

// hashFunction вычисляет хеш для ключа
func (ht *HashTable) hashFunction(key string) int {
    h := fnv.New32a()
    h.Write([]byte(key))
    return int(h.Sum32()) % ht.size
}

// hashFunction2 вычисляет вторичный хеш для двойного хеширования
func (ht *HashTable) hashFunction2(key string) int {
    h := fnv.New32a()
    h.Write([]byte(key))
    return 7 - int(h.Sum32())%7
}

// Insert добавляет элемент в хеш-таблицу
func (ht *HashTable) Insert(key, value string) {
    index := ht.hashFunction(key)
    step := ht.hashFunction2(key)
    for i := 0; i < ht.size; i++ {
        newIndex := (index + i*step) % ht.size
        if ht.table[newIndex] == nil {
            ht.table[newIndex] = &NodeHT{key: key, value: value}
            return
        } else if ht.table[newIndex].key == key {
            ht.table[newIndex].value = value
            return
        }
    }
    fmt.Println("Хеш-таблица заполнена, невозможно добавить элемент.")
}

// Get возвращает значение по ключу
func (ht *HashTable) Get(key string) string {
    index := ht.hashFunction(key)
    step := ht.hashFunction2(key)
    for i := 0; i < ht.size; i++ {
        newIndex := (index + i*step) % ht.size
        if ht.table[newIndex] != nil && ht.table[newIndex].key == key {
            return ht.table[newIndex].value
        }
    }
    return "Элемент не найден"
}

// Remove удаляет элемент по ключу
func (ht *HashTable) Remove(key string) {
    index := ht.hashFunction(key)
    step := ht.hashFunction2(key)
    for i := 0; i < ht.size; i++ {
        newIndex := (index + i*step) % ht.size
        if ht.table[newIndex] != nil && ht.table[newIndex].key == key {
            ht.table[newIndex] = nil
            return
        }
    }
    fmt.Println("Элемент не найден")
}

// Display выводит элементы хеш-таблицы
func (ht *HashTable) Display() {
    for i := 0; i < ht.size; i++ {
        if ht.table[i] != nil {
            fmt.Printf("[%d] %s: %s\n", i, ht.table[i].key, ht.table[i].value)
        } else {
            fmt.Printf("[%d] Пусто\n", i)
        }
    }
}