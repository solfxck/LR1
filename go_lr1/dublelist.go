package main

import "fmt"

// DubleList представляет двусвязный список
type DubleList struct {
    head *Node
    tail *Node
}

// PushHead добавляет элемент в начало списка
func (dl *DubleList) PushHead(value string) {
    node := &Node{data: value, next: dl.head, prev: nil}
    if dl.head != nil {
        dl.head.prev = node
    }
    dl.head = node
    if dl.tail == nil {
        dl.tail = node
    }
}

// PushTail добавляет элемент в конец списка
func (dl *DubleList) PushTail(value string) {
    node := &Node{data: value, next: nil, prev: dl.tail}
    if dl.tail != nil {
        dl.tail.next = node
    }
    dl.tail = node
    if dl.head == nil {
        dl.head = node
    }
}

// PopHead удаляет элемент из начала списка
func (dl *DubleList) PopHead() {
    if dl.head == nil {
        fmt.Println("Список пуст!")
        return
    }
    dl.head = dl.head.next
    if dl.head != nil {
        dl.head.prev = nil
    } else {
        dl.tail = nil
    }
}

// PopTail удаляет элемент из конца списка
func (dl *DubleList) PopTail() {
    if dl.tail == nil {
        fmt.Println("Список пуст!")
        return
    }
    dl.tail = dl.tail.prev
    if dl.tail != nil {
        dl.tail.next = nil
    } else {
        dl.head = nil
    }
}

// PopValue удаляет элемент по значению
func (dl *DubleList) PopValue(value string) bool {
    if dl.head == nil {
        fmt.Println("Список пуст!")
        return false
    }
    current := dl.head
    for current != nil && current.data != value {
        current = current.next
    }
    if current == nil {
        fmt.Println("Элемент не найден!")
        return false
    }
    if current.prev != nil {
        current.prev.next = current.next
    } else {
        dl.head = current.next
    }
    if current.next != nil {
        current.next.prev = current.prev
    } else {
        dl.tail = current.prev
    }
    return true
}

// Search ищет элемент по значению
func (dl *DubleList) Search(value string) bool {
    current := dl.head
    for current != nil {
        if current.data == value {
            return true
        }
        current = current.next
    }
    return false
}

// Display выводит элементы списка
func (dl *DubleList) Display() {
    if dl.head == nil {
        fmt.Println("Список пуст!")
        return
    }
    current := dl.head
    for current != nil {
        fmt.Print(current.data, " ")
        current = current.next
    }
    fmt.Println()
}