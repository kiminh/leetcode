package main

import (
	"fmt"
	"testing"

	mylist "github.com/galois-advertising/leetcode/container/list"
)

func Test(t *testing.T) {
	l := mylist.NewList(nil)
	l.PushBack(1, 2, 3, 4, 5, 6, 7, 8, 9)
	new_l := reverseBetween(l.Head(), 3, 7)
	for new_l != nil {
		fmt.Printf("%d\t", new_l.Val)
		new_l = new_l.Next
	}
}
