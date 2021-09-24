package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type tree struct {
	arr []int
}

type pair struct {
	val int
	pos int
}

func (t *tree) sum(i int) int {
	ans := 0
	for i > 0 {
		ans += t.arr[i]
		i -= (i & -i)
	}
	return ans
}

func (t *tree) update(i int) {
	for i < len(t.arr) {
		t.arr[i]++
		i += (i & -i)
	}
}

func newTree(M int) *tree {
	t := new(tree)
	t.arr = make([]int, M+1)
	return t
}

func count(A []int, B int) int64 {
	C := make([]pair, len(A)-1)
	for i := 0; i < len(C); i++ {
		C[i].val = A[i+1] ^ B
		C[i].pos = i + 1
	}
	sort.Slice(C, func(i, j int) bool {
		if C[i].val == C[j].val {
			return C[i].pos > C[j].pos
		}
		return C[i].val < C[j].val
	})
	t := newTree(len(C))
	var result int64
	for _, p := range C {
		result += int64(t.sum(p.pos - 1))
		t.update(p.pos)
	}
	return result
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N, M int
	fmt.Fscan(reader, &N, &M)
	A := make([]int, M+1)
	for i := 1; i <= M; i++ {
		fmt.Fscan(reader, &A[i])
	}
	exp := 0
	for N != (1 << exp) {
		exp++
	}
	B := 0
	var cnt int64
	for i := 0; i < exp; i++ {
		offCnt := count(A, B)
		onCnt := count(A, B|(1<<i))
		if offCnt > onCnt {
			cnt = offCnt
		} else {
			B |= (1 << i)
			cnt = onCnt
		}
	}
	fmt.Println(cnt)
}
