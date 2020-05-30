package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	for _, s := range subsets([]int{9, 0, 3, 5, 7}) {
		for _, i := range s {
			fmt.Printf("%d,", i)
		}
		fmt.Println()
	}
}
