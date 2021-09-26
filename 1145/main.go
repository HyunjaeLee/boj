package main

import "fmt"

func main() {
	var arr [5]int
	for i := 0; i < 5; i++ {
		fmt.Scan(&arr[i])
	}
	x := 0
	for {
		x++
		cnt := 0
		for _, a := range arr {
			if x%a == 0 {
				cnt++
			}
		}
		if cnt >= 3 {
			break
		}
	}
	fmt.Println(x)
}
