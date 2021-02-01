package main

import "fmt"

func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	return
}

func swap2(s1, s2 string) (ss1, ss2 string) {
	ss2 = s1
	ss1 = s2
	return
}

func main() {
	fmt.Println(split(17))
	fmt.Println(swap2("str1", "str2"))
}
