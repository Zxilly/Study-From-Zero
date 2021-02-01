package main

import "fmt"

func main() {
	s := []int{2, 3, 5, 7, 11, 13}
	printSlice3(s)

	// Slice the slice to give it zero length.
	s = s[:0]
	printSlice3(s)

	// Extend its length.
	s = s[:4]
	printSlice3(s)

	// Drop its first two values.
	s = s[2:]
	printSlice3(s)

	s = s[1:4]
	printSlice3(s)
}

func printSlice3(s []int) {
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
}
