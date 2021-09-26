package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var writer *bufio.Writer

type Node struct {
	key   int
	left  *Node
	right *Node
}

func (n *Node) Print() {
	if n == nil {
		return
	}
	n.left.Print()
	n.right.Print()
	fmt.Fprintln(writer, n.key)
}

func (n *Node) Put(x int) {
	if x < n.key {
		if n.left == nil {
			n.left = &Node{key: x}
		} else {
			n.left.Put(x)
		}
	} else {
		if n.right == nil {
			n.right = &Node{key: x}
		} else {
			n.right.Put(x)
		}
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	scanner.Scan()
	x, _ := strconv.Atoi(scanner.Text())
	root := Node{key: x}
	for scanner.Scan() {
		x, _ = strconv.Atoi(scanner.Text())
		root.Put(x)
	}
	root.Print()
}
