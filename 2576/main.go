package main

import "fmt"

func main() {
	sum := 0
	min := 100
	var num int
	for i := 0; i < 7; i++ {
		fmt.Scanln(&num)
		if (num & 1) == 0 { // 짝수인 경우
			continue
		}
		sum += num
		if num < min {
			min = num
		}
	}
	if sum == 0 {
		fmt.Println("-1")
	} else {
		fmt.Println(sum)
		fmt.Println(min)
	}
}
