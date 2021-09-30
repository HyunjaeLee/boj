package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	A := new(big.Int)
	B := new(big.Int)
	fmt.Fscan(reader, A, B)
	product := new(big.Int).Mul(A, B)
	fmt.Fprintln(writer, product)
}
