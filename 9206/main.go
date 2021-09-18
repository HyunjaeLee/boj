package main

import (
	"fmt"
	"math"
)

func volume(a, b, h float64) float64 {
	pi := math.Acos(-1)
	n := int(h * 1e6)
	dx := h / float64(n)
	sum := 0.0
	for k := 0; k < n; k++ {
		x := dx*float64(k) + dx/2
		y := a*math.Exp(-x*x) + b*math.Sqrt(x)
		sum += y * y
	}
	return pi * sum * dx
}

func main() {
	var V float64
	var N int
	fmt.Scan(&V, &N)
	min := 1e9
	idx := -1
	for i := 0; i < N; i++ {
		var a, b, h float64
		fmt.Scan(&a, &b, &h)
		vol := volume(a, b, h)
		diff := math.Abs(V - vol)
		if diff < min {
			min = diff
			idx = i
		}
	}
	fmt.Println(idx)
}
