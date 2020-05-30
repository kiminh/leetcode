package main

import (
	"fmt"
	"testing"

	mylist "github.com/galois-advertising/leetcode/container/list"
)

func Test(t *testing.T) {
	l := mylist.NewList(nil)
	l.PushBack(1, 2, 3, 3, 4, 4, 5, 6, 6, 6, 7, 8, 8)
	new_l := deleteDuplicates(l.Head())
	for new_l != nil {
		fmt.Printf("%d\t", new_l.Val)
		new_l = new_l.Next
	}
	fmt.Println("")
}
