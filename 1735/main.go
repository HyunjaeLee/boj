package main

import (
	"fmt"
	"math/big"
)

func main() {
	var a, b int64
	fmt.Scan(&a, &b)
	x := big.NewRat(a, b)
	fmt.Scan(&a, &b)
	y := big.NewRat(a, b)
	sum := new(big.Rat)
	sum.Add(x, y)
	fmt.Println(sum.Num(), sum.Denom())
}
