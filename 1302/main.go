package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N int
	fmt.Fscan(reader, &N)
	counts := make(map[string]int)
	for i := 0; i < N; i++ {
		var title string
		fmt.Fscan(reader, &title)
		counts[title]++
	}
	max := 0
	answer := ""
	for title, count := range counts {
		if count > max || (count == max && title < answer) {
			max = count
			answer = title
		}
	}
	fmt.Println(answer)
}
