package main

import mylist "github.com/galois-advertising/leetcode/container/list"

func getIntersectionNode(headA, headB *mylist.ListNode) *mylist.ListNode {
	if headA == nil || headB == nil {
		return nil
	}
	pa, pb := headA, headB
	pa_touch_end, pb_touch_end := false, false
	for pa != pb {
		if pa.Next == nil {
			if pa_touch_end == false {
				pa = headB
				pa_touch_end = true
			} else {
				return nil
			}
		} else {
			pa = pa.Next
		}
		if pb.Next == nil {
			if pb_touch_end == false {
				pb = headA
				pb_touch_end = true
			} else {
				return nil
			}
		} else {
			pb = pb.Next
		}
	}
	return pb
}
