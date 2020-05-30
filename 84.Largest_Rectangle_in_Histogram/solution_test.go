package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	fmt.Println(largestRectangleArea([]int{2, 1, 5, 6, 2, 3}))
	fmt.Println(largestRectangleArea([]int{2}))
}
