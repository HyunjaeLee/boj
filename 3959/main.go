package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

const g float64 = 9.81

var j, p, H, L, v2 float64

func h(x float64) float64 {
	var ret float64
	if x >= 0 && x < L/2 {
		ret = H * (1 - 2*(x/L)*(x/L))
	} else if x >= L/2 && x < L {
		ret = 2 * H * (x/L - 1) * (x/L - 1)
	} else if x >= L {
		ret = 0
	} else {
		ret = H
	}
	return ret
}

func dh(x float64) float64 {
	var ret float64
	if x >= 0 && x < L/2 {
		ret = -4 * H * x / (L * L)
	} else if x >= L/2 && x < L {
		ret = 4 * H / L * (x/L - 1)
	} else {
		ret = 0
	}
	return ret
}

func f(x float64) float64 {
	return -g*x*x/(2*v2) + H + p
}

func df(x float64) float64 {
	return -g * x / v2
}

func search() float64 {
	var left, mid, right, epsilon float64
	left = 0
	right = 1e9
	epsilon = 1e-9
	for i := 0; i < 64; i++ {
		mid = (left + right) / 2
		diff := f(mid) - h(mid)
		if diff > epsilon {
			left = mid
		} else if diff < -epsilon {
			right = mid
		} else {
			break
		}
	}
	return mid
}

func speed(x float64) float64 {
	return math.Sqrt(v2 + g*g*x*x/v2)
}

func degree(x float64) float64 {
	tanh := dh(x)
	tanf := df(x)
	rad := math.Atan((tanh - tanf) / (1 + tanh*tanf))
	return math.Abs(rad) * 180 / math.Pi
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	var t int
	fmt.Fscan(reader, &t)
	for c := 0; c < t; c++ {
		fmt.Fscan(reader, &j, &p, &H, &L)
		v2 = 2 * g * j
		x := search()
		v := speed(x)
		deg := degree(x)
		fmt.Fprintln(writer, x, v, deg)
	}
	writer.Flush()
}
