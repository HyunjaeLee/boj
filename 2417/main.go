package main

import "fmt"

func main() {
	var n uint64
	fmt.Scan(&n)
	left := uint64(0)
	right := uint64(3037000500)
	for left < right {
		mid := (left + right) / 2
		if mid*mid < n {
			left = mid + 1
		} else {
			right = mid
		}
	}
	fmt.Println(left)
}
