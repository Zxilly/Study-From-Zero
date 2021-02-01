package main

import "fmt"

var (
	a int     = -1
	b float32 = 3.3
	c float64 = 6.6
)

func main() {
	var d bool = true
	v := 3.3 // change me!
	fmt.Printf("v is of type %T\n", v)
	x := a
	fmt.Printf("x is of type %T\n", x)
	y := b
	fmt.Printf("y is of type %T\n", y)
	z := c
	fmt.Printf("z is of type %T\n", z)
	_ = d
}
