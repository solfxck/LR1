package main

import "fmt"

// Queue представляет очередь
type Queue struct {
    head *Node
    tail *Node
}

// Push добавляет элемент в конец очереди
func (q *Queue) Push(value string) {
    node := &Node{data: value, next: nil}
    if q.head == nil {
        q.head = node
        q.tail = node
    } else {
        q.tail.next = node
        q.tail = node
    }
}

// Pop удаляет элемент из начала очереди
func (q *Queue) Pop() {
    if q.head == nil {
        fmt.Println("Очередь пуста!")
    } else {
        temp := q.head
        q.head = q.head.next
        fmt.Println("Удаленный элемент:", temp.data)
        if q.head == nil {
            q.tail = nil
        }
    }
}

// Display выводит элементы очереди
func (q *Queue) Display() {
    if q.head == nil {
        fmt.Println("Очередь пуста!")
    } else {
        current := q.head
        for current != nil {
            fmt.Print(current.data, " ")
            current = current.next
        }
        fmt.Println()
    }
}