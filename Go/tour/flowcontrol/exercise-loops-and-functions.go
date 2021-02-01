package main

import (
	"fmt"
	"time"
)

func Sqrt(x float64) float64 {
	if x == 0 {
		return 0
	}
	var result float64 = 1
	var pre float64 = 0
	for result != pre {
		pre = result
		result = (result + x/result) / 2
	}
	return result
}

func main() {
	startTime := time.Now().UnixNano()
	for i := 0; i < 1e7; i++ {
		Sqrt(float64(i))
	}
	endTime := time.Now().UnixNano()
	fmt.Println(float64((endTime - startTime) / 1e6))
}
