package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	matrix := Constructor([][]int{
		{3, 0, 1, 4, 2},
		{5, 6, 3, 2, 1},
		{1, 2, 0, 1, 5},
		{4, 1, 0, 1, 7},
		{1, 0, 3, 0, 5},
	})
	fmt.Println(matrix.SumRegion(1, 1, 3, 3))

}
