package main

import (
	"bufio"
	"fmt"
	"os"
)

type pair struct {
	num    int
	weight int
}

var (
	list     [][]pair
	diameter int
)

func dfs(v pair) int {
	first := 0
	second := 0
	for _, child := range list[v.num] {
		weight := dfs(child) + child.weight
		if weight > first {
			first, second = weight, first
		} else if weight > second {
			second = weight
		}
	}
	sum := first + second
	if sum > diameter {
		diameter = sum
	}
	return first
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(reader, &n)
	list = make([][]pair, n+1)
	for i := 0; i < n; i++ {
		var parent, child, weight int
		fmt.Fscan(reader, &parent, &child, &weight)
		list[parent] = append(list[parent], pair{num: child, weight: weight})
	}
	dfs(pair{1, 0})
	fmt.Println(diameter)
}
