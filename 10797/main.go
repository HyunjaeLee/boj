package main

import "fmt"

func main() {
	var day, car int
	fmt.Scan(&day)
	count := 0
	for i := 0; i < 5; i++ {
		fmt.Scan(&car)
		if car == day {
			count++
		}
	}
	fmt.Println(count)
}
