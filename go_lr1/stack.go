package main

import "fmt"

// Stack представляет стек
type Stack struct {
    top *Node
}

// Push добавляет элемент на вершину стека
func (s *Stack) Push(value string) {
    node := &Node{data: value, next: s.top}
    s.top = node
}

// Pop удаляет элемент с вершины стека
func (s *Stack) Pop() {
    if s.top == nil {
        fmt.Println("Стек пуст!")
    } else {
        temp := s.top
        s.top = s.top.next
        fmt.Println("Удаленный элемент:", temp.data)
    }
}

// Display выводит элементы стека
func (s *Stack) Display() {
    if s.top == nil {
        fmt.Println("Стек пуст!")
    } else {
        current := s.top
        for current != nil {
            fmt.Print(current.data, " ")
            current = current.next
        }
        fmt.Println()
    }
}