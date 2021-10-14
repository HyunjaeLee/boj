package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')
	s, _ := reader.ReadString('\n')
	var cnt_2, cnt_e int
	for _, r := range s {
		if r == '2' {
			cnt_2++
		} else if r == 'e' {
			cnt_e++
		}
	}
	if cnt_2 > cnt_e {
		fmt.Println("2")
	} else if cnt_2 < cnt_e {
		fmt.Println("e")
	} else {
		fmt.Println("yee")
	}
}
