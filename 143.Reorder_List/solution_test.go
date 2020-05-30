package main
import (
	"fmt"
	"testing"
)


func Test(t *testing.T) {
	input := &ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, &ListNode{5, nil}}}}}
	reorderList(input)
	for n := input; n != nil; n = n.Next {
		fmt.Printf("%d\t", n.Val)
	}
	fmt.Println("")
}