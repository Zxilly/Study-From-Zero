package main

import (
	"fmt"
	"math"
)

type Abser interface {
	Abs() float64
}

type MyFloat2 float64

type Vertex6 struct {
	X, Y float64
}

func main() {
	var a Abser
	f := MyFloat2(-math.Sqrt2)
	v := Vertex6{3, 4}

	a = f // a MyFloat2 implements Abser
	// _ = v
	a = &v // a *Vertex6 implements Abser

	// In the following line, v is a Vertex6 (not *Vertex6)
	// and does NOT implement Abser.

	fmt.Println(a.Abs())
}

func (f MyFloat2) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

func (v *Vertex6) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}
