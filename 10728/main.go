package main

import (
	"bufio"
	"fmt"
	"os"
)

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	var T int
	fmt.Fscan(reader, &T)
	for c := 0; c < T; c++ {
		var N int
		fmt.Fscan(reader, &N)
		k := 0
		for ; k < 7; k++ {
			if N >= (1<<k) && N < (1<<(k+1)) {
				break
			}
		}
		if k == 0 {
			fmt.Fprintln(writer, "1\n1")
			continue
		}
		length := min(N-(1<<(k-1))+1, 1<<k)
		fmt.Fprintln(writer, length)
		for i := 0; i < length-1; i++ {
			fmt.Fprintf(writer, "%d ", (1<<(k-1))+i)
		}
		fmt.Fprintln(writer, (1<<(k-1))+length-1)
	}
	writer.Flush()
}
