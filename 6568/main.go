package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	var mem [32]uint8
	var adder, pc uint8
	for {
		n, _ := fmt.Fscanf(reader, "%b\n", &mem[0])
		if n != 1 {
			break
		}
		for i := 1; i < 32; i++ {
			fmt.Fscanf(reader, "%b\n", &mem[i])
		}
		adder = 0
		pc = 0
		for {
			op := mem[pc]
			pc = (pc + 1) & 0x1F
			t := op >> 5
			x := op & 0x1F
			if t == 0b000 {
				mem[x] = adder
			} else if t == 0b001 {
				adder = mem[x]
			} else if t == 0b010 {
				if adder == 0 {
					pc = x
				}
			} else if t == 0b100 {
				adder--
			} else if t == 0b101 {
				adder++
			} else if t == 0b110 {
				pc = x
			} else if t == 0b111 {
				break
			}
		}
		fmt.Fprintf(writer, "%08b\n", adder)
	}
}
