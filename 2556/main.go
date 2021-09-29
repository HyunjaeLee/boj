package main

import (
	"fmt"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	for i := 0; i < N; i++ {
		fmt.Println(strings.Repeat("*", N))
	}
}
