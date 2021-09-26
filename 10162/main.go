package main

import "fmt"

func main() {
	var t int
	fmt.Scan(&t)
	a := t / 300
	t %= 300
	b := t / 60
	t %= 60
	c := t / 10
	t %= 10
	if t == 0 {
		fmt.Println(a, b, c)
	} else {
		fmt.Println("-1")
	}
}
