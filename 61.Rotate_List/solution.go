package main

import (
	mylist "github.com/galois-advertising/leetcode/container/list"
)

func rotateRight(head *mylist.ListNode, k int) *mylist.ListNode {
	l := mylist.NewList(head)
	mylist.Rotate(l, k)
	return l.Head()
}
