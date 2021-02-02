package main

import (
	"fmt"
	"math"
)

type Vertex1 struct {
	X, Y float64
}

func Abs(v Vertex1) float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func (t Vertex1) Abs() float64 {
	return math.Sqrt(t.X*t.X + t.Y*t.Y)
}

func main() {
	v := Vertex1{3, 4}
	fmt.Println(Abs(v))
	fmt.Println(v.Abs())
}
