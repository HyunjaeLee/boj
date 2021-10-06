package main

import "fmt"

func main() {
	var T int
	fmt.Scan(&T)
	for i := 0; i < T; i++ {
		var N, denom int
		var num float64
		fmt.Scan(&N)
		for j := 0; j < N; j++ {
			var C int
			var G float64
			fmt.Scan(&C, &G)
			num += float64(C) * G
			denom += C
		}
		fmt.Printf("%d %.1f\n", denom, num/float64(denom))
	}
}
