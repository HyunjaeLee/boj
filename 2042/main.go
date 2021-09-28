package main

import (
	"bufio"
	"fmt"
	"os"
)

type FenwickTree []int64

func (f FenwickTree) Sum(i int) int64 {
	var ret int64
	for i > 0 {
		ret += f[i]
		i &= i - 1
	}
	return ret
}

func (f FenwickTree) Add(i int, val int64) {
	for i < len(f) {
		f[i] += val
		i += i & -i
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	var N, M, K int
	fmt.Fscan(reader, &N, &M, &K)
	arr := make([]int64, N+1)
	tree := make(FenwickTree, N+1)
	for i := 1; i <= N; i++ {
		var x int64
		fmt.Fscan(reader, &x)
		arr[i] = x
		tree.Add(i, x)
	}
	for i := 0; i < M+K; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		if a == 1 {
			var c int64
			fmt.Fscan(reader, &c)
			tree.Add(b, c-arr[b])
			arr[b] = c
		} else if a == 2 {
			var c int
			fmt.Fscan(reader, &c)
			fmt.Fprintln(writer, tree.Sum(c)-tree.Sum(b-1))
		}
	}
}
