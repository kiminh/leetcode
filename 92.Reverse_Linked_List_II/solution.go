package main

import mylist "github.com/galois-advertising/leetcode/container/list"

func reverseBetween(head *mylist.ListNode, m int, n int) *mylist.ListNode {
	lst := mylist.NewList(head)
	mylist.ReverseBetween(lst, m, n)
	return lst.Head()
}
