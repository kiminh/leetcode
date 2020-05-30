package main

import (
	mylist "github.com/galois-advertising/leetcode/container/list"
)

func sortList(head *mylist.ListNode) *mylist.ListNode {
	l := new(mylist.List).Init(head)
	l = mylist.Sort(l)
	return l.Head()
}
