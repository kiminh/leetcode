package main

import mylist "github.com/galois-advertising/leetcode/container/list"

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *mylist.ListNode) *mylist.ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	lst := mylist.NewList(head)
	var l, r, ntail, nhead *mylist.ListNode = lst.Root(), nil, lst.Head(), nil
	prev, cur := lst.Root(), lst.Head()
	for cur != nil {
		if cur.Next == nil {
			nhead = cur
		}
		tprev, tcur := prev, cur
		prev, cur = cur, cur.Next
		tcur.Next = tprev
	}
	l.Next = nhead
	ntail.Next = r
	return lst.Head()
}
