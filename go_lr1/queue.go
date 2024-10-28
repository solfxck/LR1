package main

import "fmt"

type Queue struct {
	head *Node1
	tail *Node1
}

func (q *Queue) Push(value string) {
	node := &Node1{data: value}
	if q.head == nil {
		q.head = node
		q.tail = node
	} else {
		q.tail.next = node
		q.tail = node
	}
}

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
