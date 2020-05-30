package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	root := &TreeNode{-10, &TreeNode{9, nil, nil}, &TreeNode{20, &TreeNode{15, nil, nil}, &TreeNode{7, nil, nil}}}
	fmt.Println(maxPathSum(root))

}
