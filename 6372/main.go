package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	for scanner.Scan() {
		mem := scanner.Bytes()
		if mem[0] == '8' {
			break
		}
		for i, c := range mem {
			if c >= '0' && c <= '9' {
				mem[i] = c & 0xF
			} else if c >= 'A' && c <= 'F' {
				mem[i] = c - 55
			}
		}
		p := byte(0)
		var A, B byte
		stop := false
		for !stop {
			code := mem[p]
			p++
			switch code {
			case 0:
				arg := (mem[p] << 4) | mem[p+1]
				p += 2
				A = mem[arg]
			case 1:
				arg := (mem[p] << 4) | mem[p+1]
				p += 2
				mem[arg] = A
			case 2:
				A, B = B, A
			case 3:
				sum := A + B
				A = sum & 0xF
				B = sum >> 4
			case 4:
				A = (A + 1) & 0xF
			case 5:
				A = (A - 1) & 0xF
			case 6:
				if A == 0 {
					arg := (mem[p] << 4) | mem[p+1]
					p = arg
				} else {
					p += 2
				}
			case 7:
				arg := (mem[p] << 4) | mem[p+1]
				p = arg
			case 8:
				stop = true
			}
		}
		for i, c := range mem {
			if c >= 0 && c <= 9 {
				mem[i] = c | '0'
			} else if c >= 0xA && c <= 0xF {
				mem[i] = c + 55
			}
		}
		fmt.Fprintln(writer, string(mem))
	}
}
