package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	fmt.Println(uniquePathsWithObstacles([][]int{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}))
}
