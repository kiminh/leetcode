package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return head
	}
	pos := head
	var last *ListNode = nil
	for pos != nil {
		if pos.Next == nil {
			pos = pos.Next
			//
		} else {
			temp := pos.Next.Next
			pos.Next.Next = pos
			if pos == head {
				head = pos.Next
			} else if last != nil {
				last.Next = pos.Next
			}
			pos.Next = temp
			//last.Next = pos
			last = pos
			pos = pos.Next
		}
	}
	return head
}
