package main

import "fmt"

type Person struct {
	Name string
	Age  int
}

func (p Person) String() string { // 这玩意儿就是 python 的 __str__
	return fmt.Sprintf("%s (%d years)\n", p.Name, p.Age)
}

func main() {
	a := Person{"Arthur Dent", 42}
	z := Person{"Zaphod Beeblebrox", 9001}
	fmt.Print(a)
	fmt.Print(z)
}
