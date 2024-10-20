package main

import "fmt"

// List представляет односвязный список
type List struct {
    head *Node
    tail *Node
}

// PushHead добавляет элемент в начало списка
func (l *List) PushHead(value string) {
    node := &Node{data: value, next: l.head}
    if l.head == nil {
        l.tail = node
    }
    l.head = node
}

// PushTail добавляет элемент в конец списка
func (l *List) PushTail(value string) {
    node := &Node{data: value, next: nil}
    if l.tail == nil {
        l.head = node
        l.tail = node
    } else {
        l.tail.next = node
        l.tail = node
    }
}

// PopHead удаляет элемент из начала списка
func (l *List) PopHead() {
    if l.head == nil {
        fmt.Println("Список пуст!")
        return
    }
    l.head = l.head.next
    if l.head == nil {
        l.tail = nil
    }
}

// PopTail удаляет элемент из конца списка
func (l *List) PopTail() {
    if l.head == nil {
        fmt.Println("Список пуст!")
        return
    }
    if l.head == l.tail {
        l.head = nil
        l.tail = nil
        return
    }
    current := l.head
    for current.next != l.tail {
        current = current.next
    }
    current.next = nil
    l.tail = current
}

// PopValue удаляет элемент по значению
func (l *List) PopValue(value string) bool {
    if l.head == nil {
        fmt.Println("Список пуст!")
        return false
    }
    if l.head.data == value {
        l.PopHead()
        return true
    }
    current := l.head
    for current.next != nil && current.next.data != value {
        current = current.next
    }
    if current.next == nil {
        fmt.Println("Элемент не найден!")
        return false
    }
    current.next = current.next.next
    if current.next == nil {
        l.tail = current
    }
    return true
}

// Search ищет элемент по значению
func (l *List) Search(value string) bool {
    current := l.head
    for current != nil {
        if current.data == value {
            return true
        }
        current = current.next
    }
    return false
}

// Display выводит элементы списка
func (l *List) Display() {
    if l.head == nil {
        fmt.Println("Список пуст!")
        return
    }
    current := l.head
    for current != nil {
        fmt.Print(current.data, " ")
        current = current.next
    }
    fmt.Println()
}