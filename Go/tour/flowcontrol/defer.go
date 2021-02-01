package main

import "fmt"

func test() {
	defer fmt.Println("testb")
	fmt.Println("testa")
}

func main() {
	defer fmt.Println("world")
	fmt.Println("hello")
	test()
}
