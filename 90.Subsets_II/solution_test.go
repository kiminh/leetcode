package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	for _, s := range subsetsWithDup([]int{1, 2, 2, 3, 3}) {
		for _, i := range s {
			fmt.Printf("%d,", i)
		}
		fmt.Println()
	}
}
