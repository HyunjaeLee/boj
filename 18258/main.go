package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	queue := list.New()
	var N int
	fmt.Fscan(reader, &N)
	for i := 0; i < N; i++ {
		var s string
		fmt.Fscan(reader, &s)
		if s == "push" {
			var X int
			fmt.Fscan(reader, &X)
			queue.PushBack(X)
		} else if s == "pop" {
			if queue.Len() == 0 {
				fmt.Fprintln(writer, "-1")
			} else {
				elem := queue.Front()
				fmt.Fprintln(writer, elem.Value)
				queue.Remove(elem)
			}
		} else if s == "size" {
			fmt.Fprintln(writer, queue.Len())
		} else if s == "empty" {
			if queue.Len() == 0 {
				fmt.Fprintln(writer, "1")
			} else {
				fmt.Fprintln(writer, "0")
			}
		} else if s == "front" {
			if queue.Len() == 0 {
				fmt.Fprintln(writer, "-1")
			} else {
				fmt.Fprintln(writer, queue.Front().Value)
			}
		} else if s == "back" {
			if queue.Len() == 0 {
				fmt.Fprintln(writer, "-1")
			} else {
				fmt.Fprintln(writer, queue.Back().Value)
			}
		}
	}
}
