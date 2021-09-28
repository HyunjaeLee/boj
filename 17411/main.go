package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const MOD = 1_000_000_007

type Node struct {
	Len int
	Cnt int
}

func max(a, b Node) Node {
	if a.Len > b.Len {
		return a
	}
	return b
}

type Tree struct {
	n   int
	arr []Node
}

func NewTree(size int) Tree {
	n := 1
	for n < size {
		n *= 2
	}
	arr := make([]Node, n*2)
	return Tree{n: n, arr: arr}
}

func (t Tree) query(left, right, node, nodeLeft, nodeRight int) Node {
	if right < nodeLeft || nodeRight < left {
		return Node{}
	}
	if left <= nodeLeft && nodeRight <= right {
		return t.arr[node]
	}
	mid := (nodeLeft + nodeRight) / 2
	lRes := t.query(left, right, node*2, nodeLeft, mid)
	rRes := t.query(left, right, node*2+1, mid+1, nodeRight)
	if lRes.Len == rRes.Len {
		return Node{Len: lRes.Len, Cnt: (lRes.Cnt + rRes.Cnt) % MOD}
	} else {
		return max(lRes, rRes)
	}
}

func (t Tree) Query(left, right int) Node {
	return t.query(left, right, 1, 0, t.n-1)
}

func (t Tree) Update(i int, val Node) {
	i += t.n
	t.arr[i] = val
	for i > 1 {
		i /= 2
		if t.arr[i*2].Len == t.arr[i*2+1].Len {
			t.arr[i] = Node{Len: t.arr[i*2].Len, Cnt: (t.arr[i*2].Cnt + t.arr[i*2+1].Cnt) % MOD}
		} else {
			t.arr[i] = max(t.arr[i*2], t.arr[i*2+1])
		}
	}
}

type Pair struct {
	val int
	idx int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N int
	fmt.Fscan(reader, &N)
	A := make([]Pair, N)
	for i := 0; i < N; i++ {
		var v int
		fmt.Fscan(reader, &v)
		A[i] = Pair{val: v, idx: i}
	}
	sort.Slice(A, func(i, j int) bool {
		if A[i].val == A[j].val {
			return A[i].idx > A[j].idx
		}
		return A[i].val < A[j].val
	})
	t := NewTree(N)
	for _, p := range A {
		res := t.Query(0, p.idx)
		if res.Len == 0 {
			t.Update(p.idx, Node{Len: 1, Cnt: 1})
		} else {
			t.Update(p.idx, Node{Len: res.Len + 1, Cnt: res.Cnt})
		}
	}
	ans := t.Query(0, N-1)
	fmt.Println(ans.Len, ans.Cnt)
}
