package main

import (
	"fmt"
	"testing"

	mylist "github.com/galois-advertising/leetcode/container/list"
)

func Test(t *testing.T) {
	l := mylist.NewList(nil)
	l.PushBack(1)
	l.PushBack(2)
	l.PushBack(3)
	l.PushBack(4)
	l.PushBack(5)
	l.PushBack(6)
	l.PushBack(7)

	new_l := rotateRight(l.Head(), 2)
	for pos := new_l; pos != nil; pos = pos.Next {
		fmt.Printf("%d\t", pos.Val)
	}
	fmt.Println("")

}
