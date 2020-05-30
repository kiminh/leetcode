package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	for _, v := range combine(5, 3) {
		fmt.Println(v)
	}
}
