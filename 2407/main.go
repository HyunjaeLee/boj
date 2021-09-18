package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
)

var dp [101][51]*big.Int

func combination(n, m int64) *big.Int {
	var result *big.Int
	if n-m < m {
		result = combination(n, n-m)
	} else if m == 0 {
		result = big.NewInt(1)
	} else if m == 1 {
		result = big.NewInt(n)
	} else if dp[n][m] != nil {
		result = dp[n][m]
	} else {
		result = new(big.Int).Add(combination(n-1, m), combination(n-1, m-1))
		dp[n][m] = result
	}
	return result
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	var n, m int64
	fmt.Fscan(reader, &n, &m)
	fmt.Fprintln(writer, combination(n, m))
	writer.Flush()
}
