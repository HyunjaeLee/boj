package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD int64 = 1000000007

func pow2(exp int64) int64 {
	if exp == 1 {
		return 2
	}
	pow := pow2(exp / 2)
	ret := pow * pow
	if exp%2 == 1 {
		ret *= 2
	}
	return ret % MOD
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N int
	fmt.Fscan(reader, &N)
	var C, K, sum int64
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &C, &K)
		if K == 1 {
			sum += C
		} else if K > 1 {
			sum += C * K % MOD * pow2(K-1) % MOD
		}
	}
	fmt.Println(sum % MOD)
}
