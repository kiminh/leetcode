package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	input := []*ListNode{
		&ListNode{1, &ListNode{4, &ListNode{5, nil}}},
		&ListNode{1, &ListNode{3, &ListNode{4, nil}}},
		&ListNode{2, &ListNode{6, nil}},
	}

	res := mergeKLists(input)
	for res != nil {
		fmt.Printf("%d\t", res.Val)
		res = res.Next
	}

}
