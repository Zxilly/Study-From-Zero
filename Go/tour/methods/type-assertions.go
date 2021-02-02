package main

import "fmt"

func main() {
	var i interface{} = "hello"

	s := i.(string)
	fmt.Println(s)

	s, ok := i.(string)
	fmt.Println(s, ok)

	f, ok := i.(float64)
	fmt.Println(f, ok)

	k, _ := i.(float64) // panic // 不接受ok参数，断言会直接抛出错误
	fmt.Println(k)
}
