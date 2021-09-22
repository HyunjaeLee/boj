package main

import "fmt"

func main() {
	var a, d, k float64
	fmt.Scan(&a, &d, &k)
	pr := []float64{d / 100}
	for {
		next := pr[len(pr)-1] * (1 + k/100)
		if next >= 1 {
			pr = append(pr, 1)
			break
		}
		pr = append(pr, next)
	}
	var sum float64
	for i := 0; i < len(pr); i++ {
		acc := a * float64(i+1)
		for _, p := range pr[:i] {
			acc *= 1 - p
		}
		sum += acc * pr[i]
	}
	fmt.Println(sum)
}
