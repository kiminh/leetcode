package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	fmt.Println(maxProfit([]int{3, 3, 5, 0, 0, 3, 1, 4}))
	fmt.Println(maxProfit([]int{1, 2, 3, 4, 5}))
}
