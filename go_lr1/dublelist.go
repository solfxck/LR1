package main

import "fmt"

type DubleList struct {
	head *Node
	tail *Node
	size int
}

func (dl *DubleList) PushHead(value string) {
	node := &Node{data: value}
	if dl.head == nil {
		dl.head = node
		dl.tail = node
	} else {
		node.next = dl.head
		dl.head.prev = node
		dl.head = node
	}
	dl.size++
}

func (dl *DubleList) PushTail(value string) {
	node := &Node{data: value}
	if dl.tail == nil {
		dl.head = node
		dl.tail = node
	} else {
		node.prev = dl.tail
		dl.tail.next = node
		dl.tail = node
	}
	dl.size++
}

func (dl *DubleList) PopHead() {
	if dl.head == nil {
		fmt.Println("Список пуст!")
		return
	}
	temp := dl.head
	dl.head = dl.head.next
	if dl.head != nil {
		dl.head.prev = nil
	} else {
		dl.tail = nil
	}
	temp.next = nil
	dl.size--
}

func (dl *DubleList) PopTail() {
	if dl.head == nil {
		fmt.Println("Список пуст!")
		return
	}
	if dl.head == dl.tail {
		dl.head = nil
		dl.tail = nil
	} else {
		temp := dl.tail
		dl.tail = dl.tail.prev
		dl.tail.next = nil
		temp.prev = nil
	}
	dl.size--
}

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
	current.next = nil
	current.prev = nil
	dl.size--
	return true
}

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
