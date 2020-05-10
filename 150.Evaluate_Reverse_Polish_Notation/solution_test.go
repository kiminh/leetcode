package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	fmt.Println(evalRPN2([]string{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}))

}
