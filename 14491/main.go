package main

import (
	"fmt"
	"strconv"
)

func main() {
	var T int64
	fmt.Scan(&T)
	s := strconv.FormatInt(T, 9)
	fmt.Println(s)
}
