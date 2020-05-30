package main

import (
	"fmt"
	"testing"

	mylist "github.com/galois-advertising/leetcode/container/list"
)

func Test(t *testing.T) {
	lst := mylist.NewList(nil)
	lst.PushBack(1, 2, 3, 4, 5, 6, 7, 8, 9)
	pos := reverseList(lst.Head())
	for pos != nil {
		fmt.Printf("%d\t", pos.Val)
		pos = pos.Next
	}
	fmt.Println("")

}
