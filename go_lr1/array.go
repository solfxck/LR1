package main

import "fmt"

// Array представляет динамический массив
type Array struct {
    data     []string
    capacity int
}

// NewArray создает новый массив с начальной емкостью
func NewArray(initialCapacity int) *Array {
    return &Array{data: make([]string, 0, initialCapacity), capacity: initialCapacity}
}

// Push добавляет элемент в конец массива
func (a *Array) PushEnd(value string) {
    a.data = append(a.data, value)
}

// Push добавляет элемент по индексу
func (a *Array) Push(index int, value string) {
    if index < 0 || index > len(a.data) || len(a.data) >= a.capacity {
        fmt.Println("Невозможно добавить элемент. Ошибка индекса или превышен максимальный размер.")
        return
    }
    a.data = append(a.data[:index], append([]string{value}, a.data[index:]...)...)
}

// Get возвращает элемент по индексу
func (a *Array) Get(index int) string {
    if index < 0 || index >= len(a.data) {
        return "Неверный индекс"
    }
    return a.data[index]
}

// Pop удаляет элемент по индексу
func (a *Array) Pop(index int) {
    if index < 0 || index >= len(a.data) {
        fmt.Println("Неверный индекс!")
        return
    }
    a.data = append(a.data[:index], a.data[index+1:]...)
}

// Replace заменяет элемент по индексу
func (a *Array) Replace(index int, value string) {
    if index < 0 || index >= len(a.data) {
        fmt.Println("Неверный индекс!")
        return
    }
    a.data[index] = value
}

// Length возвращает длину массива
func (a *Array) Length() int {
    return len(a.data)
}

// Display выводит элементы массива
func (a *Array) Display() {
    if len(a.data) == 0 {
        fmt.Println("Массив пуст!")
        return
    }
    for _, value := range a.data {
        fmt.Print(value, " ")
    }
    fmt.Println()
}