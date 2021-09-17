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
	reader.ReadString('\n')
	var N, M big.Int
	fmt.Fscan(reader, &N, &M)
	product := new(big.Int)
	product.Mul(&N, &M)
	fmt.Fprintln(writer, product)
	writer.Flush()
}
