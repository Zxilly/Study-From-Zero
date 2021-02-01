package main

import (
	"golang.org/x/tour/pic"
)

func Pic(dx, dy int) (tmp [][]uint8) {
	tmp = make([][]uint8, dx)

	for i := range tmp {
		tmp[i] = make([]uint8, dy)
	}

	for i := 0; i < dx; i++ {
		for j := 0; j < dy; j++ {
			if i+j == dx {
				tmp[i][j] = 255
			} else {
				tmp[i][j] = 0
			}
		}
	}

	// fmt.Println(tmp)

	return
}

func main() {
	pic.Show(Pic)
}
