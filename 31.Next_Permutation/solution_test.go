package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	input := []int{1, 2, 3, 4, 5}
	fmt.Println(input)
	for i := 0; i < 120; i++ {
		nextPermutation(input)
		fmt.Println(input)
	}
}
