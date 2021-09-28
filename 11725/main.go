package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	list [][]int
	sol  []int
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	var N int
	fmt.Fscan(reader, &N)
	list = make([][]int, N+1)
	sol = make([]int, N+1)
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		list[a] = append(list[a], b)
		list[b] = append(list[b], a)
	}
	dfs(0, 1)
	for i := 2; i <= N; i++ {
		fmt.Fprintln(writer, sol[i])
	}
}

func dfs(parent, this int) {
	sol[this] = parent
	for _, child := range list[this] {
		if child == parent {
			continue
		}
		dfs(this, child)
	}
}
