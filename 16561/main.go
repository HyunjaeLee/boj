package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	k := n/3 - 1
	fmt.Println(k * (k - 1) / 2)
}
