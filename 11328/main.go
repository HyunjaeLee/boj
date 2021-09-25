package main

import (
	"bufio"
	"fmt"
	"os"
)

func check(a, b string) bool {
	if len(a) != len(b) {
		return false
	}
	var arr [26]int
	for _, r := range a {
		arr[r-'a']++
	}
	for _, r := range b {
		arr[r-'a']--
	}
	for _, c := range arr {
		if c != 0 {
			return false
		}
	}
	return true
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	var N int
	fmt.Fscan(reader, &N)
	for i := 0; i < N; i++ {
		var a, b string
		fmt.Fscan(reader, &a, &b)
		if check(a, b) {
			fmt.Fprintln(writer, "Possible")
		} else {
			fmt.Fprintln(writer, "Impossible")
		}
	}
}
