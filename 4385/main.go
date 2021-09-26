package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var mem [1000]int
	for i := 0; scanner.Scan(); i++ {
		mem[i], _ = strconv.Atoi(scanner.Text())
	}
	var reg [10]int
	var count, p int
	flag := true
	for flag {
		count++
		a := mem[p] / 100
		b := mem[p] % 100 / 10
		c := mem[p] % 10
		p++
		switch a {
		case 1:
			flag = false
		case 2:
			reg[b] = c
		case 3:
			reg[b] = (reg[b] + c) % 1000
		case 4:
			reg[b] = (reg[b] * c) % 1000
		case 5:
			reg[b] = reg[c]
		case 6:
			reg[b] = (reg[b] + reg[c]) % 1000
		case 7:
			reg[b] = (reg[b] * reg[c]) % 1000
		case 8:
			reg[b] = mem[reg[c]]
		case 9:
			mem[reg[c]] = reg[b]
		case 0:
			if reg[c] != 0 {
				p = reg[b]
			}
		}
	}
	fmt.Println(count)
}
