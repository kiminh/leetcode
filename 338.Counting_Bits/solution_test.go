package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	for _, v := range countBits(5) {
		fmt.Printf("%d, ", v)
	}
	fmt.Println("")

}
