package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) (bool, *ListNode) {
	if head == nil {
		return false, nil
	}
	if head.Next == head {
		return true, head
	}
	p_slow, p_fast := head, head
	for true {
		p_slow = p_slow.Next
		if p_slow == nil {
			return false, nil
		}
		p_fast = p_fast.Next
		if p_fast == nil {
			return false, nil
		}
		p_fast = p_fast.Next
		if p_fast == nil {
			return false, nil
		}
		if p_slow == p_fast {
			return true, p_slow
		}
	}
	return false, nil
}

func detectCycle(head *ListNode) *ListNode {
	if has, meet := hasCycle(head); has {
		p1, p2 := head, meet
		for p1 != p2 {
			p1, p2 = p1.Next, p2.Next
		}
		return p1
	}
	return nil
}
