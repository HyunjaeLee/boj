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
	var p int
	fmt.Fscan(reader, &p)
	for i := 0; i < p; i++ {
		var n int
		var d, a, b, f float64
		fmt.Fscan(reader, &n, &d, &a, &b, &f)
		fmt.Fprintln(writer, n, f*d/(a+b))
	}
}
