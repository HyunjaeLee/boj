package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	for {
		s, _ := reader.ReadString('\n')
		s = strings.TrimSpace(s)
		if s == "0" {
			break
		} else if len(s) == 1 {
			fmt.Fprintln(writer, s)
			continue
		}
		dr := 0
		for _, r := range s {
			dr += int(r & 0xF)
		}
		for dr >= 10 {
			tmp := dr
			dr = 0
			for tmp > 0 {
				dr += tmp % 10
				tmp /= 10
			}
		}
		fmt.Fprintln(writer, dr)
	}
}
