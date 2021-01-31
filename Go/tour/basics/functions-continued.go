package main

import "fmt"

func add2(x, y int) float64 {
	return float64(x + y)
}

func main() {
	fmt.Println(add2(42, 13))
}
