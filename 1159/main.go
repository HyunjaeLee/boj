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
	var count [26]int
	for i := 0; i < N; i++ {
		var s string
		fmt.Fscan(reader, &s)
		count[s[0]-'a']++
	}
	ok := false
	for i, v := range count {
		if v >= 5 {
			fmt.Printf("%c", i+'a')
			ok = true
		}
	}
	if !ok {
		fmt.Print("PREDAJA")
	}
}
