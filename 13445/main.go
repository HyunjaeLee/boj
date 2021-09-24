package main

import (
	"bufio"
	"fmt"
	"os"
)

type Node struct {
	count int
	next  []*Node
}

func NewNode() *Node {
	n := new(Node)
	n.next = make([]*Node, 2)
	return n
}

type Trie struct {
	len  int
	root *Node
}

func NewTrie(len int) *Trie {
	t := new(Trie)
	t.len = len
	t.root = NewNode()
	return t
}

func (t *Trie) Put(x int) {
	node := t.root
	for i := t.len - 1; i >= 0; i-- {
		bit := (x >> i) & 1
		if node.next[bit] == nil {
			node.next[bit] = NewNode()
		}
		node = node.next[bit]
		node.count++
	}
}

func (t *Trie) Count(x, k int) int {
	node := t.root
	result := 0
	for i := t.len - 1; i >= 0; i-- {
		xBit := (x >> i) & 1
		kBit := (k >> i) & 1
		if kBit == 0 {
			node = node.next[xBit]
		} else {
			if node.next[xBit] != nil {
				result += node.next[xBit].count
			}
			node = node.next[xBit^1]
		}
		if node == nil {
			break
		}
	}
	return result
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N, K int
	fmt.Fscan(reader, &N, &K)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}
	fmt.Println(solve(N, K, A))
}

func solve(N, K int, A []int) int {
	if K >= (1 << 17) {
		return N * (N + 1) / 2
	}
	trie := NewTrie(17)
	acc := 0
	result := 0
	trie.Put(0)
	for _, x := range A {
		acc ^= x
		result += trie.Count(acc, K)
		trie.Put(acc)
	}
	return result
}
