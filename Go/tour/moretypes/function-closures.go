package main

import (
	"fmt"
	"math"
)

func adder() func(int) int {
	sum := 0
	return func(x int) int {
		sum += x
		return sum
	}
}

func main() {
	pos, neg, test := adder(), adder(), adder()
	for i := 0; i < 10; i++ {
		fmt.Println(
			pos(i),
			neg(-2*i),
			test(int(math.Pow(2, float64(i))))+1,
		)
	}
}
