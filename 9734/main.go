package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strconv"
)

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	e := [10]int64{1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9}
	r, _ := regexp.Compile("([0-9]+)\\.([0-9]*)\\(([0-9]+)\\)")
	for scanner.Scan() {
		s := scanner.Text()
		group := r.FindStringSubmatch(s)
		n1, _ := strconv.ParseInt(group[1]+group[2], 10, 64)
		n2, _ := strconv.ParseInt(group[3], 10, 64)
		p1 := e[len(group[2])]
		p2 := e[len(group[3])]
		num := n1*(p2-1) + n2
		denom := p1 * (p2 - 1)
		div := gcd(num, denom)
		fmt.Fprintf(writer, "%s = %d / %d\n", s, num/div, denom/div)
	}
	writer.Flush()
}
