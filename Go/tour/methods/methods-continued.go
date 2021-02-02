package main

import (
	"fmt"
	"math"
)

type MyFloat float64

// 不能为内置类型声明接收者，但是可以为内置类型的别名声明

func (f MyFloat) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

func main() {
	f := MyFloat(-math.Sqrt2)
	fmt.Println(f.Abs())
}
