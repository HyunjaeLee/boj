package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	sum := 0
	for _, v := range strings.Split(s, ",") {
		n, _ := strconv.Atoi(v)
		sum += n
	}
	fmt.Println(sum)
}
