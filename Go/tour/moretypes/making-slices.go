package main

import "fmt"

func main() {
	a := make([]int, 5)
	printSlice2("a", a)

	b := make([]int, 0, 5)
	printSlice2("b", b)

	c := b[:2]
	printSlice2("c", c)

	d := c[2:5]
	printSlice2("d", d)

	e := [5]int{0, 1, 2, 3, 4}
	_ = e
}

func printSlice2(s string, x []int) {
	fmt.Printf("%s len=%d cap=%d %v %T\n",
		s, len(x), cap(x), x, x)
}
