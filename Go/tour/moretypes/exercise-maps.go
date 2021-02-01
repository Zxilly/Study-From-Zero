package main

import (
	"golang.org/x/tour/wc"
	"strings"
)

func WordCount(s string) (tmp map[string]int) {
	tmp = map[string]int{}
	li := strings.Fields(s)
	for _, v := range li {
		tmp[v] = tmp[v] + 1
	}
	return
}

func main() {
	wc.Test(WordCount)
}
