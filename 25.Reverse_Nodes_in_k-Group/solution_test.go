package main

import (
	"fmt"
	"testing"

	mylist "github.com/galois-advertising/leetcode/container/list"
)

func Test(T *testing.T) {
	lst := mylist.NewList(nil)
	lst.PushBack(1, 2, 3, 1, 2, 3, 1, 2, 3, 1)
	new_l := reverseKGroup(lst.Head(), 3)
	for new_l != nil {
		fmt.Printf("%d\t", new_l.Val)
		new_l = new_l.Next
	}
}
