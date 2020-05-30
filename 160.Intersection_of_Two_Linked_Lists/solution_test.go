package main

import (
	"fmt"
	"testing"

	mylist "github.com/galois-advertising/leetcode/container/list"
)

func Test(t *testing.T) {
	A, B := mylist.NewList(nil), mylist.NewList(nil)
	A.PushBack(1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21)
	B.PushBack(2)
	res := getIntersectionNode(A.Head(), B.Head())
	if res != nil {
		fmt.Println(res.Val)
	}

}
