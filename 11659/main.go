package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	var N, M int
	fmt.Fscan(reader, &N, &M)
	psum := make([]int, N+1)
	for i := 1; i <= N; i++ {
		var num int
		fmt.Fscan(reader, &num)
		psum[i] = psum[i-1] + num
	}
	for c := 0; c < M; c++ {
		var i, j int
		fmt.Fscan(reader, &i, &j)
		fmt.Fprintln(writer, psum[j]-psum[i-1])
	}
	writer.Flush()
}
