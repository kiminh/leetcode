package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	fmt.Println(minSubArrayLen(15, []int{5, 1, 3, 5, 10, 7, 4, 9, 2, 8}))
}
