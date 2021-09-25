package main

import (
	"fmt"
	"syscall"
)

var (
	data []byte
	pos  int
	size int
)

func read() int64 {
	var n int64
	for pos < size && data[pos] >= '0' && data[pos] <= '9' {
		n = (n << 1) + (n << 3) + int64(data[pos]&0xF)
		pos++
	}
	pos++
	return n
}

func main() {
	var st syscall.Stat_t
	syscall.Fstat(syscall.Stdin, &st)
	size = int(st.Size)
	data, _ = syscall.Mmap(syscall.Stdin, 0, size, syscall.PROT_READ, syscall.MAP_PRIVATE)
	N := read()
	var sum int64
	for i := int64(0); i < N; i++ {
		sum += read()
	}
	fmt.Println(N)
	fmt.Println(sum)
	syscall.Munmap(data)
}
