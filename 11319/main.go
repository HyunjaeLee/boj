package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	S, _ := strconv.Atoi(line)
	for i := 0; i < S; i++ {
		s, _ := reader.ReadString('\n')
		var consonants, vowels int
		for _, r := range s {
			if r == ' ' || r == '\n' {
				continue
			}
			low := r | 32
			if low == 'a' || low == 'e' || low == 'i' || low == 'o' || low == 'u' {
				vowels++
			} else {
				consonants++
			}
		}
		fmt.Fprintln(writer, consonants, vowels)
	}
}
