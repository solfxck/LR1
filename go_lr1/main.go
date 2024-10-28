package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func loadQueueFromFile(queue *Queue, filename string) {
	file, err := os.Open(filename)
	if err != nil {
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		queue.Push(scanner.Text())
	}
}

func loadStackFromFile(stack *Stack, filename string) {
	file, err := os.Open(filename)
	if err != nil {
		return
	}
	defer file.Close()

	values := make([]string, 0, 100)
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		values = append(values, scanner.Text())
	}

	for i := len(values) - 1; i >= 0; i-- {
		stack.Push(values[i])
	}
}

func loadArrayFromFile(array *Array, filename string) {
	file, err := os.Open(filename)
	if err != nil {
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		array.PushEnd(scanner.Text())
	}
}

func loadListFromFile(list *List, filename string) {
	file, err := os.Open(filename)
	if err != nil {
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		list.PushTail(scanner.Text())
	}
}

func loadDubleListFromFile(dubleList *DubleList, filename string) {
	file, err := os.Open(filename)
	if err != nil {
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		dubleList.PushTail(scanner.Text())
	}
}

func loadHashTableFromFile(hashTable *HashTable, filename string) {
	file, err := os.Open(filename)
	if err != nil {
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		parts := strings.Split(scanner.Text(), " ")
		if len(parts) == 2 {
			hashTable.Insert(parts[0], parts[1])
		}
	}
}

func loadAVLFromFile(avl *AVL, filename string) {
	file, err := os.Open(filename)
	if err != nil {
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		key, err := strconv.Atoi(scanner.Text())
		if err == nil {
			avl.Insert(key)
		}
	}
}

func saveQueueToFile(queue *Queue, filename string) {
	file, err := os.Create(filename)
	if err != nil {
		return
	}
	defer file.Close()

	current := queue.head
	for current != nil {
		fmt.Fprintln(file, current.data)
		current = current.next
	}
}

func saveStackToFile(stack *Stack, filename string) {
	file, err := os.Create(filename)
	if err != nil {
		return
	}
	defer file.Close()

	current := stack.top
	for current != nil {
		fmt.Fprintln(file, current.data)
		current = current.next
	}
}

func saveArrayToFile(array *Array, filename string) {
	file, err := os.Create(filename)
	if err != nil {
		return
	}
	defer file.Close()

	for i := 0; i < array.size; i++ {
		fmt.Fprintln(file, array.data[i])
	}
}

func saveListToFile(list *List, filename string) {
	file, err := os.Create(filename)
	if err != nil {
		return
	}
	defer file.Close()

	current := list.head
	for current != nil {
		fmt.Fprintln(file, current.data)
		current = current.next
	}
}

func saveDubleListToFile(dubleList *DubleList, filename string) {
	file, err := os.Create(filename)
	if err != nil {
		return
	}
	defer file.Close()

	current := dubleList.head
	for current != nil {
		fmt.Fprintln(file, current.data)
		current = current.next
	}
}

func saveHashTableToFile(hashTable *HashTable, filename string) {
	file, err := os.Create(filename)
	if err != nil {
		return
	}
	defer file.Close()

	for i := 0; i < hashTable.size; i++ {
		current := hashTable.table[i]
		for current != nil {
			fmt.Fprintf(file, "%s %s\n", current.key, current.value)
			current = current.next
		}
	}
}

func saveAVLToFile(avl *AVL, filename string) {
	file, err := os.Create(filename)
	if err != nil {
		return
	}
	defer file.Close()

	avl.saveToFile(avl.root, file)
}

func processCommand(command string, queue *Queue, stack *Stack, array *Array, list *List, dubleList *DubleList, hashTable *HashTable, avl *AVL) {
	var key, value string
	var intKey int

	switch command {
	case "EXIT":
		return
	case "QPUSH":
		fmt.Scan(&value)
		queue.Push(value)
	case "QPOP":
		queue.Pop()
	case "QPRINT":
		queue.Display()
	case "SPUSH":
		fmt.Scan(&value)
		stack.Push(value)
	case "SPOP":
		stack.Pop()
	case "SPRINT":
		stack.Display()
	case "MPUSH_T":
		fmt.Scan(&value)
		array.PushEnd(value)
	case "MPUSH_ID":
		var index int
		fmt.Scan(&index, &value)
		array.Push(index, value)
	case "MGET":
		var index int
		fmt.Scan(&index)
		fmt.Println(array.Get(index))
	case "MPOP_ID":
		var index int
		fmt.Scan(&index)
		array.Pop(index)
	case "MREP":
		var index int
		fmt.Scan(&index, &value)
		array.Replace(index, value)
	case "MLEN":
		fmt.Println(array.Length())
	case "MPRINT":
		array.Display()
	case "LPUSH_H":
		fmt.Scan(&value)
		list.PushHead(value)
	case "LPUSH_T":
		fmt.Scan(&value)
		list.PushTail(value)
	case "LPOP_H":
		list.PopHead()
	case "LPOP_T":
		list.PopTail()
	case "LPOP_V":
		fmt.Scan(&value)
		list.PopValue(value)
	case "LSEARCH":
		fmt.Scan(&value)
		if list.Search(value) {
			fmt.Println("Элемент найден")
		} else {
			fmt.Println("Элемент не найден")
		}
	case "LPRINT":
		list.Display()
	case "DPUSH_H":
		fmt.Scan(&value)
		dubleList.PushHead(value)
	case "DPUSH_T":
		fmt.Scan(&value)
		dubleList.PushTail(value)
	case "DPOP_H":
		dubleList.PopHead()
	case "DPOP_T":
		dubleList.PopTail()
	case "DPOP_V":
		fmt.Scan(&value)
		dubleList.PopValue(value)
	case "DSEARCH":
		fmt.Scan(&value)
		if dubleList.Search(value) {
			fmt.Println("Элемент найден")
		} else {
			fmt.Println("Элемент не найден")
		}
	case "DPRINT":
		dubleList.Display()
	case "HPUSH":
		fmt.Scan(&key, &value)
		hashTable.Insert(key, value)
	case "HGET":
		fmt.Scan(&key)
		fmt.Println(hashTable.Get(key))
	case "HPOP":
		fmt.Scan(&key)
		hashTable.Remove(key)
	case "HPRINT":
		hashTable.Display()
	case "TPUSH":
		fmt.Scan(&intKey)
		avl.Insert(intKey)
	case "TPOP":
		fmt.Scan(&intKey)
		avl.Remove(intKey)
	case "TSEARCH":
		fmt.Scan(&intKey)
		if avl.Search(intKey) {
			fmt.Println("Элемент найден")
		} else {
			fmt.Println("Элемент не найден")
		}
	case "TPRINT":
		avl.Display()
	default:
		fmt.Println("Неверная команда.")
	}
}

func main() {
	queue := &Queue{}
	stack := &Stack{}
	array := NewArray()
	list := &List{}
	dubleList := &DubleList{}
	hashTable := NewHashTable(10)
	avl := &AVL{}

	loadQueueFromFile(queue, "txt/queue.txt")
	loadStackFromFile(stack, "txt/stack.txt")
	loadArrayFromFile(array, "txt/array.txt")
	loadListFromFile(list, "txt/list.txt")
	loadDubleListFromFile(dubleList, "txt/dublelist.txt")
	loadHashTableFromFile(hashTable, "txt/hashtable.txt")
	loadAVLFromFile(avl, "txt/avl.txt")

	scanner := bufio.NewScanner(os.Stdin)
	for {
		fmt.Print("> ")
		scanner.Scan()
		command := scanner.Text()
		if command == "EXIT" {
			break
		}
		processCommand(command, queue, stack, array, list, dubleList, hashTable, avl)
	}

	saveQueueToFile(queue, "txt/queue.txt")
	saveStackToFile(stack, "txt/stack.txt")
	saveArrayToFile(array, "txt/array.txt")
	saveListToFile(list, "txt/list.txt")
	saveDubleListToFile(dubleList, "txt/dublelist.txt")
	saveHashTableToFile(hashTable, "txt/hashtable.txt")
	saveAVLToFile(avl, "txt/avl.txt")
}
