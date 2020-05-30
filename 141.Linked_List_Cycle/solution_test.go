package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	head := &ListNode{1, nil}
	two := &ListNode{2, nil}
	head.Next = two
	three := &ListNode{3, nil}
	two.Next = three
	four := &ListNode{4, nil}
	three.Next = four
	four.Next = two
	fmt.Println(hasCycle(head))
}
