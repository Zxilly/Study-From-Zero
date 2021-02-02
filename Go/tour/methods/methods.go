package main

import (
	"fmt"
	"math"
)

type Vertex7 struct {
	X, Y float64
}

func (v Vertex7) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func (v Vertex7) Test() int {
	return 1
}

func test2(v Vertex7) int {
	return 20
}

func main() {
	v := Vertex7{3, 4}
	fmt.Println(v.Abs())
	fmt.Println(v.Test())
	fmt.Println(test2(v))
}
