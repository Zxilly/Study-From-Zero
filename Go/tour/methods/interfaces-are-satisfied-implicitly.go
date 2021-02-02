package main

import "fmt"

type I interface {
	M()
	N()
}

type T struct {
	S string
}

func (t T) N() {
	fmt.Println("this is N")
	// panic("implement me")
}

// This method means type T implements the interface I,
// but we don't need to explicitly declare that it does so.
func (t T) M() {
	fmt.Println(t.S)
}

func main() {
	var i I = T{S: "hello"}
	j := T{"test"}
	i.M()
	i.N()

	var test int = 1

	fmt.Printf("%T %T %T", i, j, test)
}
