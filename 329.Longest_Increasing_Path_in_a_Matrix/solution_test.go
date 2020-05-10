package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	input := [][]int{
		{9, 9, 4},
		{6, 6, 8},
		{2, 1, 1},
	}
	fmt.Println(longestIncreasingPath(input))
}
