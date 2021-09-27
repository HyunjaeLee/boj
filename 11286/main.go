package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

type AbsHeap []int

func (h AbsHeap) Len() int {
	return len(h)
}

func (h AbsHeap) Less(i, j int) bool {
	if abs(h[i]) == abs(h[j]) {
		return h[i] < h[j]
	}
	return abs(h[i]) < abs(h[j])
}

func (h AbsHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *AbsHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *AbsHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func abs(n int) int {
	if n < 0 {
		n = -n
	}
	return n
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	var N int
	fmt.Fscan(reader, &N)
	var h AbsHeap
	for i := 0; i < N; i++ {
		var x int
		fmt.Fscan(reader, &x)
		if x == 0 {
			if len(h) == 0 {
				fmt.Fprintln(writer, "0")
			} else {
				fmt.Fprintln(writer, heap.Pop(&h))
			}
		} else {
			heap.Push(&h, x)
		}
	}
}
