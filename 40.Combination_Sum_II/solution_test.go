package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	res := combinationSum2([]int{19, 33, 28, 13, 25, 29, 11, 24, 11, 8, 18, 7, 6, 10, 31, 26, 28, 5, 5, 15, 24, 9, 14, 18, 13, 29, 21, 30, 21, 19, 22, 6, 17, 16, 6, 29, 32, 12, 18, 30, 7, 31, 24, 30, 28, 20, 22, 22, 20, 14, 24, 31}, 25)
	fmt.Println(res)
	fmt.Println(len(res))
}
