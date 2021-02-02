package main

import "fmt"

func main() {
	var i interface{}
	describe7(i)

	i = 42
	describe7(i)

	i = "hello"
	describe7(i)
}

func describe7(i interface{}) {
	fmt.Printf("(%v, %T)\n", i, i)
}
