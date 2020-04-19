package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	for _, v := range largestDivisibleSubset([]int{2, 4, 7, 8, 10, 111, 222, 240, 777}) {
		fmt.Printf("%d,", v)
	}
	fmt.Println()

}
