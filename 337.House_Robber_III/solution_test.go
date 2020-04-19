package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	input := IntArray{3, 4, 1, -1, -1, 3, -1, -1, 5, -1, 1, -1, -1}
	//sort.Sort(input)
	//for _, i := range input {
	//	fmt.Printf("%d,", i)
	//}
	root := create(&input, -1)
	fmt.Printf("%T\n", root.Value().(int))
	in_order(root, func(node interface{}) {
		fmt.Printf("[%d]", node.(int))
	})
	fmt.Println(rob(root.(*TreeNode)))
	return
}
