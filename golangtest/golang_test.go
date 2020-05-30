package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	m := map[int]int{}
	for i := 10; i >= 0; i-- {
		m[i] = i
	}
	for _, v := range m {
		fmt.Println(v)
	}

}
