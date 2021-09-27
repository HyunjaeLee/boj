package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var reader *bufio.Reader

func main() {
	reader = bufio.NewReader(os.Stdin)
	for c := 0; c < 3; c++ {
		result := solve()
		if result > 0 {
			fmt.Println("+")
		} else if result < 0 {
			fmt.Println("-")
		} else {
			fmt.Println("0")
		}
	}
}

func read() int64 {
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	i, _ := strconv.ParseInt(s, 10, 64)
	return i
}

func solve() int64 {
	N := read()
	list := make([]int64, N)
	for i := int64(0); i < N; i++ {
		list[i] = read()
	}
	if N == 1 {
		return list[0]
	}
	sort.Slice(list, func(i, j int) bool { return list[i] < list[j] })
	if list[0] > 0 {
		return 1
	} else if list[N-1] < 0 {
		return -1
	}
	sum := list[0] + list[N-1]
	left := int64(0)
	right := N - 1
	for right-left > 1 {
		if sum > 0 {
			left++
			if list[left] > 0 {
				break
			}
			sum += list[left]
		} else {
			right--
			if list[right] < 0 {
				break
			}
			sum += list[right]
		}
	}
	return sum
}
