package main

import (
	"bufio"
	"fmt"
	"os"
)

func bisect(x []int, target int) int {
	left := 0
	right := len(x) - 1
	for left < right {
		mid := (left + right) / 2
		if x[mid] > target {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N int
	fmt.Fscan(reader, &N)
	max := 0
	x := []int{1001}
	for i := 0; i < N; i++ {
		var a int
		fmt.Fscan(reader, &a)
		if x[len(x)-1] > a {
			if len(x) > max {
				max = len(x)
			}
			x = append(x, a)
		} else {
			x[bisect(x, a)] = a
		}
	}
	fmt.Println(max)
}
