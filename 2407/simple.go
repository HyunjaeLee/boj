package main

import (
	"fmt"
	"math/big"
)

func main() {
	var n, m int64
	fmt.Scan(&n, &m)
	fmt.Println(new(big.Int).Binomial(n, m))
}
