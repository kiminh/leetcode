package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	fmt.Println(deleteAndEarn([]int{2, 2, 3, 3, 3, 4}))
	fmt.Println(deleteAndEarn([]int{1}))

}
