package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	s := make([][]byte, 3)
	fmt.Println(s[1])
	for _, m := range solveNQueens(4) {
		for _, row := range m {
			fmt.Println(row)
		}
		fmt.Println()
	}

	//for _, row := range solveNQueens(8) {
	//	for _, node := range row {
	//		fmt.Printf("%2s", node)
	//	}
	//}

}
