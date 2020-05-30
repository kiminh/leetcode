package main

import mylist "github.com/galois-advertising/leetcode/container/list"

func deleteDuplicates(head *mylist.ListNode) *mylist.ListNode {
	res := mylist.NewList(nil)
	pos := mylist.NewList(head).Head()
	for pos != nil {
		if pos.Next == nil {
			res.PushBack(pos.Val)
		} else {
			if pos.Val == pos.Next.Val {
				val := pos.Val
				for pos != nil && pos.Val == val {
					pos = pos.Next
				}
				continue
			} else {
				res.PushBack(pos.Val)
			}
		}
		if pos != nil {
			pos = pos.Next
		}
	}
	return res.Head()
}
