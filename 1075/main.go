package main

import "fmt"

func main() {
	var N, F int
	fmt.Scan(&N, &F)
	N = N / 100 * 100
	i := 0
	for (N+i)%F != 0 {
		i++
	}
	fmt.Printf("%02d\n", i)
}
