package main

import "fmt"

func check(a []int) bool {
	for i, v := range a {
		if v != i+1 {
			return false
		}
	}
	return true
}

func main() {
	a := make([]int, 5)
	for i := 0; i < 5; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; !check(a); i = (i + 1) & 3 {
		if a[i] > a[i+1] {
			a[i], a[i+1] = a[i+1], a[i]
			for _, v := range a {
				fmt.Printf("%d ", v)
			}
			fmt.Println()
		}

	}
}
