package main

import (
	"fmt"
	"math/big"
)

const prec uint = 1024

func sin(x *big.Float) *big.Float {
	taylor := new(big.Float).SetPrec(prec).Set(x)
	coef := new(big.Float).SetPrec(prec).SetInt64(1)
	pow := new(big.Float).SetPrec(prec).Set(x)
	for i := int64(1); i < 128; i++ {
		denom := new(big.Float).SetPrec(prec).SetInt64(-2 * i * (2*i + 1))
		coef = new(big.Float).SetPrec(prec).Quo(coef, denom)
		square := new(big.Float).SetPrec(prec).Mul(x, x)
		pow = new(big.Float).SetPrec(prec).Mul(pow, square)
		term := new(big.Float).SetPrec(prec).Mul(coef, pow)
		taylor = new(big.Float).SetPrec(prec).Add(taylor, term)
	}
	return taylor
}

func mean(a, b *big.Float) *big.Float {
	sum := new(big.Float).SetPrec(prec).Add(a, b)
	two := new(big.Float).SetPrec(prec).SetInt64(2)
	return new(big.Float).SetPrec(prec).Quo(sum, two)
}

func main() {
	pi := new(big.Float).SetPrec(prec)
	pi.SetString("3.14159265358979323846264338327950288419716939937510582097494459")
	var A64, B64, C64 int64
	fmt.Scan(&A64, &B64, &C64)
	A := new(big.Float).SetPrec(prec).SetInt64(A64)
	B := new(big.Float).SetPrec(prec).SetInt64(B64)
	C := new(big.Float).SetPrec(prec).SetInt64(C64)
	x := new(big.Float).SetPrec(prec).Quo(C, A)
	n, _ := new(big.Float).SetPrec(prec).Quo(x, pi).Int64()
	var left, right, shift *big.Float
	if n%2 == 0 {
		left = new(big.Float).SetPrec(prec).Mul(new(big.Float).SetPrec(prec).SetInt64(n), pi)
		right = new(big.Float).SetPrec(prec).Set(x)
		shift = new(big.Float).SetPrec(prec).Set(left)
	} else {
		left = new(big.Float).SetPrec(prec).Set(x)
		right = new(big.Float).SetPrec(prec).Mul(new(big.Float).SetPrec(prec).SetInt64(n+1), pi)
		shift = new(big.Float).SetPrec(prec).Set(right)
	}
	var mid *big.Float
	for i := 0; i < 128; i++ {
		mid = mean(left, right)
		pro1 := new(big.Float).SetPrec(prec).Mul(A, mid)
		diff := new(big.Float).SetPrec(prec).Sub(mid, shift)
		pro2 := new(big.Float).SetPrec(prec).Mul(B, sin(diff))
		sum := new(big.Float).SetPrec(prec).Add(pro1, pro2)
		eq := new(big.Float).SetPrec(prec).Sub(sum, C)
		if eq.Sign() < 0 {
			left = new(big.Float).SetPrec(prec).Set(mid)
		} else if eq.Sign() > 0 {
			right = new(big.Float).SetPrec(prec).Set(mid)
		} else {
			break
		}
	}
	fmt.Printf("%.6f\n", mid)
}
