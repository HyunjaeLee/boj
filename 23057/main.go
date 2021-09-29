package main

import "fmt"

var set map[int64]bool

func Sum(s []int64) int64 {
	var result int64
	for _, v := range s {
		result += v
	}
	return result
}

func Binomial(s []int64, r int, sum int64) {
	if r >= len(s) {
		set[sum+Sum(s)] = true
	} else if r == 0 {
		set[sum] = true
	} else {
		Binomial(s[1:], r, sum)
		Binomial(s[1:], r-1, sum+s[0])
	}
}

func main() {
	set = make(map[int64]bool)
	var N int
	fmt.Scan(&N)
	s := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&s[i])
	}
	M := Sum(s)
	for i := 1; i <= N; i++ {
		Binomial(s, i, 0)
	}
	fmt.Println(M - int64(len(set)))
}
