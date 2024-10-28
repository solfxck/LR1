package main

import "fmt"

type Array struct {
	data     []string
	size     int
	capacity int
}

func NewArray() *Array {
	return &Array{data: make([]string, 10), size: 0, capacity: 10}
}

func (a *Array) PushEnd(value string) {
	if a.size == a.capacity {
		fmt.Println("Массив переполнен!")
		return
	}
	a.data[a.size] = value
	a.size++
}

func (a *Array) Push(index int, value string) {
	if index < 0 || index > a.size {
		fmt.Println("Индекс вне диапазона!")
		return
	}
	if a.size == a.capacity {
		fmt.Println("Массив переполнен!")
		return
	}
	for i := a.size; i > index; i-- {
		a.data[i] = a.data[i-1]
	}
	a.data[index] = value
	a.size++
}

func (a *Array) Get(index int) string {
	if index < 0 || index >= a.size {
		fmt.Println("Индекс вне диапазона!")
		return ""
	}
	return a.data[index]
}

func (a *Array) Pop(index int) {
	if index < 0 || index >= a.size {
		fmt.Println("Индекс вне диапазона!")
		return
	}
	for i := index; i < a.size-1; i++ {
		a.data[i] = a.data[i+1]
	}
	a.size--
}

func (a *Array) Replace(index int, value string) {
	if index < 0 || index >= a.size {
		fmt.Println("Индекс вне диапазона!")
		return
	}
	a.data[index] = value
}

func (a *Array) Length() int {
	return a.size
}

func (a *Array) Display() {
	if a.size == 0 {
		fmt.Println("Массив пуст!")
		return
	}
	for i := 0; i < a.size; i++ {
		fmt.Print(a.data[i], " ")
	}
	fmt.Println()
}
