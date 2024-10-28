package main

import "fmt"

type Stack struct {
	top *Node1
}

func (s *Stack) Push(value string) {
	node := &Node1{data: value, next: s.top}
	s.top = node
}

func (s *Stack) Pop() {
	if s.top == nil {
		fmt.Println("Стек пуст!")
	} else {
		temp := s.top
		s.top = s.top.next
		fmt.Println("Удаленный элемент:", temp.data)
	}
}

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
