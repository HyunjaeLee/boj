package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

type Item struct {
	value  int
	maxIdx int
	minIdx int
}

type MaxHeap []*Item

func (h MaxHeap) Len() int {
	return len(h)
}

func (h MaxHeap) Less(i, j int) bool {
	return h[i].value > h[j].value
}

func (h MaxHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
	h[i].maxIdx = i
	h[j].maxIdx = j
}

func (h *MaxHeap) Push(x interface{}) {
	n := len(*h)
	item := x.(*Item)
	item.maxIdx = n
	*h = append(*h, item)
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	item := old[n-1]
	old[n-1] = nil
	item.maxIdx = -1
	*h = old[0 : n-1]
	return item
}

type MinHeap []*Item

func (h MinHeap) Len() int {
	return len(h)
}

func (h MinHeap) Less(i, j int) bool {
	return h[i].value < h[j].value
}

func (h MinHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
	h[i].minIdx = i
	h[j].minIdx = j
}

func (h *MinHeap) Push(x interface{}) {
	n := len(*h)
	item := x.(*Item)
	item.minIdx = n
	*h = append(*h, item)
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	item := old[n-1]
	old[n-1] = nil
	item.minIdx = -1
	*h = old[0 : n-1]
	return item
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	var T int
	fmt.Fscan(reader, &T)
	for c := 0; c < T; c++ {
		var max MaxHeap
		var min MinHeap
		var k int
		fmt.Fscan(reader, &k)
		for i := 0; i < k; i++ {
			var s string
			var n int
			fmt.Fscan(reader, &s, &n)
			if s == "D" {
				if len(max) == 0 {
					continue
				}
				if n == 1 {
					item := heap.Pop(&max).(*Item)
					heap.Remove(&min, item.minIdx)
				} else if n == -1 {
					item := heap.Pop(&min).(*Item)
					heap.Remove(&max, item.maxIdx)
				}
			} else if s == "I" {
				item := &Item{value: n}
				heap.Push(&max, item)
				heap.Push(&min, item)
			}
		}
		if len(max) == 0 {
			fmt.Fprintln(writer, "EMPTY")
		} else {
			fmt.Fprintf(writer, "%d %d\n", max[0].value, min[0].value)
		}
	}
}
