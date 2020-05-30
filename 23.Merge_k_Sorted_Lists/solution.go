package main

import (
	heaplib "container/heap"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

type ListNodeHeap []*ListNode

func (h ListNodeHeap) Less(i, j int) bool {
	return h[i].Val < h[j].Val
}

func (h ListNodeHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h ListNodeHeap) Len() int {
	return len(h)
}

func (h *ListNodeHeap) Push(i interface{}) {
	*h = append(*h, i.(*ListNode))
}

func (h *ListNodeHeap) Pop() interface{} {
	n := len(*h)
	ret := (*h)[n-1]
	*h = (*h)[0 : n-1]
	return ret
}

func mergeKLists(lists []*ListNode) *ListNode {
	heap := ListNodeHeap{}
	for i, _ := range lists {
		if lists[i] != nil {
			heaplib.Push(&heap, lists[i])
			lists[i] = lists[i].Next
		}
	}
	var head *ListNode
	var cur *ListNode
	for heap.Len() != 0 {
		node := heaplib.Pop(&heap).(*ListNode)
		if node.Next != nil {
			heaplib.Push(&heap, node.Next)
		}
		if head == nil {
			head = node
			cur = node
		} else {
			cur.Next = node
			cur = cur.Next
		}
	}
	return head

}
