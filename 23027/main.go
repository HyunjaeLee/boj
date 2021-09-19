package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	var r *strings.Replacer
	if strings.ContainsRune(s, 'A') {
		r = strings.NewReplacer("B", "A", "C", "A", "D", "A", "F", "A")
		s = r.Replace(s)
	} else if strings.ContainsRune(s, 'B') {
		r = strings.NewReplacer("C", "B", "D", "B", "F", "B")
		s = r.Replace(s)
	} else if strings.ContainsRune(s, 'C') {
		r = strings.NewReplacer("D", "C", "F", "C")
		s = r.Replace(s)
	} else {
		s = strings.Repeat("A", len(s))
	}
	fmt.Println(s)
}
