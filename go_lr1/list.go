package main

import "fmt"

type List struct {
	head *Node1
	tail *Node1
	size int
}

func (l *List) PushHead(value string) {
	node := &Node1{data: value}
	if l.head == nil {
		l.head = node
		l.tail = node
	} else {
		node.next = l.head
		l.head = node
	}
	l.size++
}

func (l *List) PushTail(value string) {
	node := &Node1{data: value}
	if l.tail == nil {
		l.head = node
		l.tail = node
	} else {
		l.tail.next = node
		l.tail = node
	}
	l.size++
}

func (l *List) PopHead() {
	if l.head == nil {
		fmt.Println("Список пуст!")
		return
	}
	temp := l.head
	l.head = l.head.next
	if l.head == nil {
		l.tail = nil
	}
	temp.next = nil
	l.size--
}

func (l *List) PopTail() {
	if l.head == nil {
		fmt.Println("Список пуст!")
		return
	}
	if l.head == l.tail {
		l.head = nil
		l.tail = nil
	} else {
		current := l.head
		for current.next != l.tail {
			current = current.next
		}
		current.next = nil
		l.tail = current
	}
	l.size--
}

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
	temp := current.next
	current.next = temp.next
	if temp == l.tail {
		l.tail = current
	}
	temp.next = nil
	l.size--
	return true
}

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
