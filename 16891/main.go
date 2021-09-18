package main

import (
	"fmt"
	"math/big"
)

func main() {
	var N int64
	fmt.Scan(&N)
	m1 := int64(1)
	m2 := N * N
	v1 := new(big.Rat)
	v2 := big.NewRat(-1, 1)
	coef1 := big.NewRat(m1-m2, m1+m2)
	coef2 := big.NewRat(2*m2, m1+m2)
	coef3 := big.NewRat(2*m1, m1+m2)
	coef4 := big.NewRat(m2-m1, m1+m2)
	count := 0
	for v1.Sign() < 0 || v2.Sign() < 0 || v2.Cmp(v1) < 0 {
		if v1.Sign() < 0 {
			v1 = new(big.Rat).Neg(v1)
		} else {
			v1, v2 = new(big.Rat).Add(new(big.Rat).Mul(coef1, v1), new(big.Rat).Mul(coef2, v2)), new(big.Rat).Add(new(big.Rat).Mul(coef3, v1), new(big.Rat).Mul(coef4, v2))
		}
		count++
	}
	fmt.Println(count)
}
