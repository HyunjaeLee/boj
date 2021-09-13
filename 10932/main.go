package main

import (
	"bufio"
	"crypto/sha512"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	hash := sha512.Sum512(scanner.Bytes())
	fmt.Printf("%x\n", hash)
}
