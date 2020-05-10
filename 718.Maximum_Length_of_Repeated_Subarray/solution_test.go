package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	fmt.Println(findLength([]int{1, 2, 3, 2, 1}, []int{3, 2, 1, 4, 7}))
}
