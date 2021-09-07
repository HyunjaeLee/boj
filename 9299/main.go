package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	var T int
	fmt.Fscan(reader, &T)
	for c := 1; c <= T; c++ {
		var n int
		fmt.Fscan(reader, &n)
		fmt.Fprintf(writer, "Case %d: %d ", c, n-1)
		var coef int
		for i := n; i > 0; i-- {
			fmt.Fscan(reader, &coef)
			fmt.Fprintf(writer, "%d ", coef*i)
		}
		fmt.Fscan(reader, &coef)
		fmt.Fprintln(writer)
	}
	writer.Flush()
}
