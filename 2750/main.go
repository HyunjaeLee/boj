package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	var N int
	fmt.Fscan(reader, &N)
	s := make([]int, N)
	for i := 0; i < N; i++ {
		var num int
		fmt.Fscan(reader, &num)
		s[i] = num
	}
	sort.Ints(s)
	for _, num := range s {
		fmt.Fprintln(writer, num)
	}
	writer.Flush()
}
