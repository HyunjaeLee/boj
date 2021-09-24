package main

import (
	"container/list"
	"fmt"
)

type pair struct {
	val int64
	lv  int
}

func main() {
	var A, B int64
	fmt.Scan(&A, &B)
	q := list.New()
	q.PushBack(pair{val: A, lv: 1})
	ans := -1
	for q.Len() > 0 {
		e := q.Front()
		p := e.Value.(pair)
		q.Remove(e)
		if p.val > B {
			continue
		} else if p.val == B {
			ans = p.lv
			break
		}
		q.PushBack(pair{val: p.val*10 + 1, lv: p.lv + 1})
		q.PushBack(pair{val: p.val * 2, lv: p.lv + 1})
	}
	fmt.Println(ans)
}
