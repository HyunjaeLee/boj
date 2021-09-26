package main

import "fmt"

func main() {
	var s string
	fmt.Scan(&s)
	fmt.Println(calculate(s))
}

func valid(s string) bool {
	var stack [30]rune
	pos := 0
	for _, r := range s {
		if r == '(' || r == '[' {
			stack[pos] = r
			pos++
		} else if r == ')' {
			pos--
			if pos < 0 || stack[pos] != '(' {
				return false
			}
		} else if r == ']' {
			pos--
			if pos < 0 || stack[pos] != '[' {
				return false
			}
		}
	}
	if pos != 0 {
		return false
	}
	return true
}

func calculate(s string) int {
	if !valid(s) {
		return 0
	}
	var stack [16]int
	pos := 1
	for _, r := range s {
		if r == '(' || r == '[' {
			stack[pos] = 0
			pos++
		} else if r == ')' {
			pos--
			if stack[pos] == 0 {
				stack[pos-1] += 2
			} else {
				stack[pos-1] += 2 * stack[pos]
			}
		} else if r == ']' {
			pos--
			if stack[pos] == 0 {
				stack[pos-1] += 3
			} else {
				stack[pos-1] += 3 * stack[pos]
			}
		}
	}
	return stack[0]
}
