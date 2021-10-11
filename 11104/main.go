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
	var n int
	fmt.Fscanln(reader, &n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Fscanf(reader, "%b\n", &x)
		fmt.Fprintln(writer, x)
	}
}
