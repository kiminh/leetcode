package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	if head == nil {
		return false
	}
	if head.Next == head {
		return true
	}
	p_slow, p_fast := head, head
	for true {
		p_slow = p_slow.Next
		if p_slow == nil {
			return false
		}
		p_fast = p_fast.Next
		if p_fast == nil {
			return false
		}
		p_fast = p_fast.Next
		if p_fast == nil {
			return false
		}
		if p_slow == p_fast {
			return true
		}
	}
	return false
}
