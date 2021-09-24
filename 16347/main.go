package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	left  int
	right int
	prev  *Node
	next  *Node
}

func NewNode(left, right int) *Node {
	return &Node{left: left, right: right}
}

func (n *Node) Left() int {
	return n.left
}

type Memory struct {
	head      *Node
	available int
}

func NewMemory(size int) *Memory {
	head := NewNode(1, 1)
	tail := NewNode(size+1, size+1)
	head.next = tail
	tail.prev = head
	return &Memory{head: head, available: size}
}

func (m *Memory) Malloc(size int) *Node {
	if size > m.available {
		return nil
	}
	prev := m.head
	next := prev.next
	diff := next.left - prev.right
	for diff < size {
		prev = next
		next = prev.next
		if next == nil {
			return nil
		}
		diff = next.left - prev.right
	}
	n := NewNode(prev.right, prev.right+size)
	prev.next = n
	n.prev = prev
	next.prev = n
	n.next = next
	m.available -= size
	return n
}

func (m *Memory) Free(n *Node) {
	m.available += n.right - n.left
	n.prev.next, n.next.prev = n.next, n.prev
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	mem := NewMemory(100000)
	s, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(s))
	dict := make(map[string]*Node)
	for i := 0; i < N; i++ {
		s, _ = reader.ReadString('\n')
		s = strings.TrimSpace(s)
		if s[4] == '=' { // malloc
			name := s[:4]
			size, _ := strconv.Atoi(s[12 : len(s)-2])
			dict[name] = mem.Malloc(size)
		} else if s[4] == '(' { // free
			name := s[5:9]
			n := dict[name]
			if n != nil {
				mem.Free(n)
				dict[name] = nil
			}
		} else if s[4] == 't' { // print
			name := s[6:10]
			n := dict[name]
			if n == nil {
				fmt.Fprintln(writer, "0")
			} else {
				fmt.Fprintln(writer, n.Left())
			}
		}
	}
	writer.Flush()
}
