package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	head := &ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, &ListNode{5, nil}}}}}
	head = swapPairs(head)
	for head != nil {
		fmt.Printf("%d,", head.Val)
		head = head.Next
	}
	fmt.Println()

}
