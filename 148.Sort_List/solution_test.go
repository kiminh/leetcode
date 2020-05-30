package main

import (
	"container/list"
	"fmt"
	"testing"

	mylist "github.com/galois-advertising/leetcode/container/list"
)

func Test(t *testing.T) {
	l1 := mylist.NewList(nil)
	l1.PushBack(4)
	l1.PushBack(2)
	l1.PushBack(1)
	l1.PushBack(3)
	res := sortList(l1.Head())
	for res != nil {
		fmt.Printf("%d\t", res.Val)
		res = res.Next
	}
	fmt.Println("")

	l := list.New()
	e4 := l.PushBack(4)
	e1 := l.PushFront(1)
	l.InsertBefore(3, e4)
	l.InsertAfter(2, e1)
	// Iterate through list and print its contents.
	for e := l.Front(); e != nil; e = e.Next() {
		fmt.Println(e.Value)
	}

}
