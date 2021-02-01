package main

import "fmt"

func swap3(x *int, y *int) {
	tmp := *x
	*x = *y
	*y = tmp
}

func main() {
	i, j := 42, 2701

	/*	p := &i         // point to i
		fmt.Println(*p) // read i through the pointer
		*p = 21         // set i through the pointer
		fmt.Println(i)  // see the new value of i

		p = &j         // point to j
		*p = *p / 37   // divide j through the pointer
		fmt.Println(j) // see the new value of j*/
	fmt.Println(i, j)
	swap3(&i, &j)
	fmt.Println(i, j)

}
