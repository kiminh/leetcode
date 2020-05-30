package main

import mylist "github.com/galois-advertising/leetcode/container/list"

func reverseKGroup(head *mylist.ListNode, k int) *mylist.ListNode {
	lst := mylist.NewList(head)
	length := lst.Len()
	cnt := length / k
	if cnt == 0 {
		return head
	}
	for i, root := 0, lst.Root(); i < cnt; i++ {
		if root == nil || root.Next == nil || root.Next.Next == nil {
			break
		}
		var left, right, new_tail, new_head *mylist.ListNode = root, root.Next.Next, root.Next, root.Next
		var prev, cur *mylist.ListNode = root.Next, root.Next.Next
		var kk = k
		for kk-2 >= 0 {
			if kk-2 == 0 {
				new_head = cur
				right = cur.Next
			}
			tprev, tcur := prev, cur
			prev, cur = cur, cur.Next
			tcur.Next = tprev
			kk--
		}
		left.Next, new_tail.Next = new_head, right
		root = new_tail
	}
	return lst.Head()
}
