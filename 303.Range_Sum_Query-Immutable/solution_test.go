package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	helper := Constructor([]int{-2, 0, 3, -5, 2, -1})
	fmt.Println(helper.SumRange(0, 2))
	fmt.Println(helper.SumRange(2, 5))
	fmt.Println(helper.SumRange(0, 5))
}
