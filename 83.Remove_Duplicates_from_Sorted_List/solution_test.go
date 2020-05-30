package main

import (
	"testing"
	"fmt"
	mylist "github.com/galois-advertising/leetcode/container/list"
)


func Test(t *testing.T) {
	l := mylist.NewList(nil)
	l.PushBack(1)
	l.PushBack(1)
	l.PushBack(2)
	l.PushBack(3)
	l.PushBack(3)
	new_l := deleteDuplicates(l.Head())
	for new_l != nil {
		fmt.Printf("%d\t", new_l.Val)
		new_l = new_l.Next
	}
	fmt.Println("")

}