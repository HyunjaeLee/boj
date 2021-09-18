package main

import "fmt"

func main() {
	var cup [4]bool
	cup[1] = true
	var M int
	fmt.Scan(&M)
	for i := 0; i < M; i++ {
		var X, Y int
		fmt.Scan(&X, &Y)
		cup[X], cup[Y] = cup[Y], cup[X]
	}
	for i := 1; i <= 3; i++ {
		if cup[i] {
			fmt.Println(i)
			break
		}
	}
}
