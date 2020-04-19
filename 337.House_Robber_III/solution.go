package main

type ITreeNode interface {
	Value() interface{}
	LeftNode() ITreeNode
	RightNode() ITreeNode
	SetLeft(node ITreeNode)
	SetRight(node ITreeNode)
}
type IntArray []int

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func (t *TreeNode) Value() interface{} {
	return t.Val
}

func (t *TreeNode) LeftNode() ITreeNode {
	if t.Left == nil {
		return nil
	} else {
		return t.Left
	}
}

func (t *TreeNode) RightNode() ITreeNode {
	if t.Right == nil {
		return nil
	} else {
		return t.Right
	}
}

func (t *TreeNode) SetLeft(node ITreeNode) {
	if p, ok := node.(*TreeNode); ok {
		t.Left = p
	} else {
		t.Left = nil
	}
}

func (t *TreeNode) SetRight(node ITreeNode) {
	if p, ok := node.(*TreeNode); ok {
		t.Right = p
	} else {
		t.Right = nil
	}
}

func max(vals ...int) int {
	max := 0
	for _, i := range vals {
		if i > max {
			max = i
		}
	}
	return max
}
func rob_helper(root ITreeNode) (int, int, int) {
	if root == nil {
		return 0, 0, 0
	}
	ll, lr, ls := rob_helper(root.LeftNode())
	rl, rr, rs := rob_helper(root.RightNode())
	yes := root.Value().(int) + ll + lr + rl + rr
	no := ls + rs
	return ls, rs, max(yes, no)

}
func rob(root *TreeNode) int {
	_, _, s := rob_helper(root)
	return s

}

func create(raw_values interface{}, null_value interface{}) ITreeNode {
	values := raw_values.(*IntArray)
	if len(*values) == 0 {
		return nil
	}
	if (*values)[0] == null_value {
		*values = (*values)[1:]
		return nil
	}
	var current_root ITreeNode
	current_root = &TreeNode{(*values)[0], nil, nil}
	(*values) = (*values)[1:]
	current_root.SetLeft(create(values, null_value))
	current_root.SetRight(create(values, null_value))
	return current_root

}

func (a IntArray) Len() int {
	return len(a)
}
func (a IntArray) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}
func (a IntArray) Less(i, j int) bool {
	return a[i] < a[j]
}

func in_order(root ITreeNode, op func(interface{})) {
	if root == nil {
		return
	}
	in_order(root.LeftNode(), op)
	op(root.Value())
	in_order(root.RightNode(), op)
}

func main() {

}
