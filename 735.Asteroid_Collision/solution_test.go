package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	fmt.Println(asteroidCollision([]int{2, -1, -1, -2}))
	fmt.Println(asteroidCollision([]int{-2, 2, -1, -2}))
	fmt.Println(asteroidCollision([]int{5, 10, -5}))
	fmt.Println(asteroidCollision([]int{8, -8}))
	fmt.Println(asteroidCollision([]int{10, 2, -5}))
	fmt.Println(asteroidCollision([]int{-2, -1, 1, 2}))
}
