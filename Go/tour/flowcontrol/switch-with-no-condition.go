package main

import (
	"fmt"
	"time"
)

func main() {
	t := time.Now()
	switch { // 用来代替连续 if-else
	case t.Hour() < 12:
		fmt.Println("Good morning!")
	case t.Hour() < 17:
		fmt.Println("Good afternoon.")
	default:
		fmt.Println("Good evening.")
	}
}
