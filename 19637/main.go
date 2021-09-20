package main

import (
	"bufio"
	"fmt"
	"os"
)

type element struct {
	title string
	power int
}

func search(power int, list []*element) string {
	left := 0
	right := len(list) - 1
	for left < right {
		mid := left + (right-left)/2
		if list[mid].power < power {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return list[left].title
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	var N, M int
	fmt.Fscan(reader, &N, &M)
	var list []*element
	prevPower := -1
	for i := 0; i < N; i++ {
		elem := new(element)
		fmt.Fscan(reader, &elem.title, &elem.power)
		if elem.power > prevPower {
			list = append(list, elem)
			prevPower = elem.power
		}
	}
	for i := 0; i < M; i++ {
		var power int
		fmt.Fscan(reader, &power)
		fmt.Fprintln(writer, search(power, list))
	}
	writer.Flush()
}
