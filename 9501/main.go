package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	var t int
	fmt.Fscan(reader, &t)
	for i := 0; i < t; i++ {
		var n, d, cnt int
		fmt.Fscan(reader, &n, &d)
		for j := 0; j < n; j++ {
			var v, f, c int
			fmt.Fscan(reader, &v, &f, &c)
			if v*f >= c*d {
				cnt++
			}
		}
		fmt.Fprintln(writer, cnt)
	}
}
