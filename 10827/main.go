package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strings"
)

func pow(x *big.Int, y int) *big.Int {
	if y == 1 {
		return x
	}
	p := pow(x, y/2)
	result := new(big.Int).Mul(p, p)
	if y%2 == 1 {
		result = new(big.Int).Mul(result, x)
	}
	return result
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	var a string
	var b int
	fmt.Fscan(reader, &a, &b)
	s := strings.Split(a, ".")
	n := new(big.Int)
	n.SetString(s[0]+s[1], 10)
	power := pow(n, b)
	place := new(big.Int)
	place.SetString("1"+strings.Repeat("0", len(s[1])*b), 10)
	integer := new(big.Int).Quo(power, place)
	decimal := new(big.Int).Mod(power, place)
	fmt.Fprintf(writer, "%d.%0*d\n", integer, len(s[1])*b, decimal)
	writer.Flush()
}
