package main

import "fmt"

type I5 interface {
	M()
}

func main() {
	var i I5
	describe6(i)
	// i.M() // 空接口不能执行方法
}

func describe6(i I5) {
	fmt.Printf("(%v, %T)\n", i, i)
}
