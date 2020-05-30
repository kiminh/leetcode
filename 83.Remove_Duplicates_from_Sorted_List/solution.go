package main

import (
	mylist "github.com/galois-advertising/leetcode/container/list"
)

func deleteDuplicates(head *mylist.ListNode) *mylist.ListNode {
	l := mylist.NewList(head)
	l.AfterSortRemoveDuplicate()
	return l.Head()
}