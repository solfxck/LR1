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
        fmt.Println("Ошибка при открытии файла:", err)
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
        fmt.Println("Ошибка при открытии файла:", err)
        return
    }
    defer file.Close()

    values := []string{}
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
        fmt.Println("Ошибка при открытии файла:", err)
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
        fmt.Println("Ошибка при открытии файла:", err)
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
        fmt.Println("Ошибка при открытии файла:", err)
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
        fmt.Println("Ошибка при открытии файла:", err)
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
        fmt.Println("Ошибка при открытии файла:", err)
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
        fmt.Println("Ошибка при создании файла:", err)
        return
    }
    defer file.Close()

    current := queue.head
    for current != nil {
        file.WriteString(current.data + "\n")
        current = current.next
    }
}

func saveStackToFile(stack *Stack, filename string) {
    file, err := os.Create(filename)
    if err != nil {
        fmt.Println("Ошибка при создании файла:", err)
        return
    }
    defer file.Close()

    current := stack.top
    for current != nil {
        file.WriteString(current.data + "\n")
        current = current.next
    }
}

func saveArrayToFile(array *Array, filename string) {
    file, err := os.Create(filename)
    if err != nil {
        fmt.Println("Ошибка при создании файла:", err)
        return
    }
    defer file.Close()

    for i := 0; i < array.Length(); i++ {
        file.WriteString(array.Get(i) + "\n")
    }
}

func saveListToFile(list *List, filename string) {
    file, err := os.Create(filename)
    if err != nil {
        fmt.Println("Ошибка при создании файла:", err)
        return
    }
    defer file.Close()

    current := list.head
    for current != nil {
        file.WriteString(current.data + "\n")
        current = current.next
    }
}

func saveDubleListToFile(dubleList *DubleList, filename string) {
    file, err := os.Create(filename)
    if err != nil {
        fmt.Println("Ошибка при создании файла:", err)
        return
    }
    defer file.Close()

    current := dubleList.head
    for current != nil {
        file.WriteString(current.data + "\n")
        current = current.next
    }
}

func saveHashTableToFile(hashTable *HashTable, filename string) {
    file, err := os.Create(filename)
    if err != nil {
        fmt.Println("Ошибка при создании файла:", err)
        return
    }
    defer file.Close()

    for i := 0; i < hashTable.size; i++ {
        current := hashTable.table[i]
        for current != nil {
            file.WriteString(current.key + " " + current.value + "\n")
            current = current.next
        }
    }
}

func saveAVLToFile(avl *AVL, filename string) {
    avl.SaveToFile(filename)
}

func processCommand(command string, queue *Queue, stack *Stack, array *Array, list *List, dubleList *DubleList, hashTable *HashTable, avl *AVL) {
    parts := strings.Split(command, " ")
    switch parts[0] {
    case "EXIT":
        return
    case "QPUSH":
        if len(parts) > 1 {
            queue.Push(parts[1])
        }
    case "QPOP":
        queue.Pop()
    case "QPRINT":
        queue.Display()
    case "SPUSH":
        if len(parts) > 1 {
            stack.Push(parts[1])
        }
    case "SPOP":
        stack.Pop()
    case "SPRINT":
        stack.Display()
    case "MPUSH_T":
        if len(parts) > 1 {
            array.PushEnd(parts[1])
        }
    case "MPUSH_ID":
        if len(parts) > 2 {
            index, err := strconv.Atoi(parts[1])
            if err == nil {
                array.Push(index, parts[2])
            }
        }
    case "MGET":
        if len(parts) > 1 {
            index, err := strconv.Atoi(parts[1])
            if err == nil {
                fmt.Println(array.Get(index))
            }
        }
    case "MPOP_ID":
        if len(parts) > 1 {
            index, err := strconv.Atoi(parts[1])
            if err == nil {
                array.Pop(index)
            }
        }
    case "MREP":
        if len(parts) > 2 {
            index, err := strconv.Atoi(parts[1])
            if err == nil {
                array.Replace(index, parts[2])
            }
        }
    case "MLEN":
        fmt.Println(array.Length())
    case "MPRINT":
        array.Display()
    case "LPUSH_H":
        if len(parts) > 1 {
            list.PushHead(parts[1])
        }
    case "LPUSH_T":
        if len(parts) > 1 {
            list.PushTail(parts[1])
        }
    case "LPOP_H":
        list.PopHead()
    case "LPOP_T":
        list.PopTail()
    case "LPOP_V":
        if len(parts) > 1 {
            list.PopValue(parts[1])
        }
    case "LSEARCH":
        if len(parts) > 1 {
            if list.Search(parts[1]) {
                fmt.Println("Элемент найден")
            } else {
                fmt.Println("Элемент не найден")
            }
        }
    case "LPRINT":
        list.Display()
    case "DPUSH_H":
        if len(parts) > 1 {
            dubleList.PushHead(parts[1])
        }
    case "DPUSH_T":
        if len(parts) > 1 {
            dubleList.PushTail(parts[1])
        }
    case "DPOP_H":
        dubleList.PopHead()
    case "DPOP_T":
        dubleList.PopTail()
    case "DPOP_V":
        if len(parts) > 1 {
            dubleList.PopValue(parts[1])
        }
    case "DSEARCH":
        if len(parts) > 1 {
            if dubleList.Search(parts[1]) {
                fmt.Println("Элемент найден")
            } else {
                fmt.Println("Элемент не найден")
            }
        }
    case "DPRINT":
        dubleList.Display()
    case "HPUSH":
        if len(parts) > 2 {
            hashTable.Insert(parts[1], parts[2])
        }
    case "HGET":
        if len(parts) > 1 {
            fmt.Println(hashTable.Get(parts[1]))
        }
    case "HPOP":
        if len(parts) > 1 {
            hashTable.Remove(parts[1])
        }
    case "HPRINT":
        hashTable.Display()
    case "TPUSH":
        if len(parts) > 1 {
            key, err := strconv.Atoi(parts[1])
            if err == nil {
                avl.Insert(key)
            }
        }
    case "TPOP":
        if len(parts) > 1 {
            key, err := strconv.Atoi(parts[1])
            if err == nil {
                avl.Remove(key)
            }
        }
    case "TSEARCH":
        if len(parts) > 1 {
            key, err := strconv.Atoi(parts[1])
            if err == nil {
                if avl.Search(key) {
                    fmt.Println("Элемент найден")
                } else {
                    fmt.Println("Элемент не найден")
                }
            }
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
    array := NewArray(10)
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