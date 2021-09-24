package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var a, b string
	fmt.Fscan(reader, &a, &b)
	sumA := 0
	sumB := 0
	for _, i := range a {
		sumA += int(i & 0xF)
	}
	for _, j := range b {
		sumB += int(j & 0xF)
	}
	fmt.Println(sumA * sumB)
}
