package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	var x int
	fmt.Scan(&x)
	min := x
	max := x
	for i := 1; i < n; i++ {
		fmt.Scan(&x)
		if x < min {
			min = x
		} else if x > max {
			max = x
		}
	}
	fmt.Println(int64(min) * int64(max))
}
