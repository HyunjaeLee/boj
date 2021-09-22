package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func calc(N int, line string, writer *bufio.Writer) {
	nums := make([]int, N)
	numLen := 0
	ops := make([]rune, N)
	opLen := 0
	numPushed := false
	x := 0
	pos := 0
	for _, r := range line {
		if r >= '0' && r <= '9' {
			numPushed = false
			x = (x << 1) + (x << 3) + (int(r) & 0xF)
		} else {
			if !numPushed {
				nums[numLen] = x
				numLen++
				x = 0
				numPushed = true
			}
			ops[opLen] = r
			opLen++
			if r == 'C' {
				pos = opLen
			}
		}
	}
	if pos == 0 {
		fmt.Fprint(writer, "NO OUTPUT")
		return
	}
	slice := nums[:numLen]
	for _, op := range ops[:pos] {
		if op == 'C' {
			fmt.Fprintf(writer, "%d ", slice[0])
			continue
		}
		x := slice[0]
		slice = slice[1:]
		y := slice[0]
		if op == 'S' {
			slice[0] = x - y
		} else if op == 'M' {
			slice[0] = x * y
		} else if op == 'U' {
			slice[0] = x / y
		} else if op == 'P' {
			slice[0] = x + y
		}
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	N, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	calc(N, line, writer)
}
