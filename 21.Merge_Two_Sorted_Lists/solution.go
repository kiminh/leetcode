package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	} else if l2 == nil {
		return l1
	}
	root := &ListNode{-1, nil}
	last := root
	p1, p2 := l1, l2
	for p1 != nil && p2 != nil {
		var temp *ListNode
		if p1.Val < p2.Val {
			temp = p1
			p1 = p1.Next
		} else {
			temp = p2
			p2 = p2.Next

		}
		last.Next = temp
		last = temp
		last.Next = nil
	}
	if p1 != nil {
		last.Next = p1
	} else if p2 != nil {
		last.Next = p2
	}
	return root.Next
}
