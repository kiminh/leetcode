package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	for _, v := range permuteUnique([]int{1, 2, 3, 4, 4, 4}) {
		fmt.Println(v)
	}
}
