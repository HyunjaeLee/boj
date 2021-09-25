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
	var N int
	fmt.Fscan(reader, &N)
	dict := map[string]uint16{
		"ADD":   0b0000,
		"SUB":   0b0001,
		"MOV":   0b0010,
		"AND":   0b0011,
		"OR":    0b0100,
		"NOT":   0b0101,
		"MULT":  0b0110,
		"LSFTL": 0b0111,
		"LSFTR": 0b1000,
		"ASFTR": 0b1001,
		"RL":    0b1010,
		"RR":    0b1011,
	}
	for i := 0; i < N; i++ {
		var opcode string
		var rd, ra, rb uint16
		fmt.Fscan(reader, &opcode, &rd, &ra, &rb)
		var result uint16
		pos := len(opcode) - 1
		if opcode[pos] == 'C' {
			result = (dict[opcode[:pos]] << 12)
			result |= (1 << 11)
			result |= rb
		} else {
			result = (dict[opcode] << 12)
			result |= (rb << 1)
		}
		result |= (ra << 4)
		result |= (rd << 7)
		fmt.Fprintf(writer, "%016b\n", result)
	}
}
