package main

import (
	"fmt"
)

type ErrNegativeSqrt float64 // 自定义类型来允许成为接收器

func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("Sqrt: negative number %g", e)
}

func Sqrt(x float64) (float64, error) {
	if x < 0 {
		return 0, ErrNegativeSqrt(x)
	}
	if x == 0 {
		return 0, nil
	}
	var result float64 = 1
	var pre float64 = 0
	for result != pre {
		pre = result
		result = (result + x/result) / 2
	}
	return result, nil
}

func main() {
	fmt.Println(Sqrt(2))
	fmt.Println(Sqrt(-2))
	fmt.Println(Sqrt(-3))
}
