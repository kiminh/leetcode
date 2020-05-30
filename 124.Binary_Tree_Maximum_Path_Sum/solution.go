package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type link_map_t map[*TreeNode][]*TreeNode

func getInfo(root *TreeNode, link link_map_t) {
	if root.Left != nil {
		if _, ok := link[root]; !ok {
			link[root] = []*TreeNode{}
		}
		link[root] = append(link[root], root.Left)
		if _, ok := link[root.Left]; !ok {
			link[root.Left] = []*TreeNode{}
		}
		link[root.Left] = append(link[root.Left], root)
		getInfo(root.Left, link)
	}
	if root.Right != nil {
		if _, ok := link[root]; !ok {
			link[root] = []*TreeNode{}
		}
		link[root] = append(link[root], root.Right)
		if _, ok := link[root.Right]; !ok {
			link[root.Right] = []*TreeNode{}
		}
		link[root.Right] = append(link[root.Right], root)
		getInfo(root.Right, link)
	}
}

func max(a ...int) int {
	ret := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > ret {
			ret = a[i]
		}
	}
	return ret
}

func dfs(root *TreeNode, max_v *int) int {
	var ret int
	if root.Left != nil && root.Right != nil {
		l, r := dfs(root.Left, max_v), dfs(root.Right, max_v)
		ret = max(root.Val, l+root.Val, r+root.Val)
		*max_v = max(*max_v, root.Val+l+r)
	} else if root.Left != nil && root.Right == nil {
		ret = max(root.Val, dfs(root.Left, max_v)+root.Val)
	} else if root.Left == nil && root.Right != nil {
		ret = max(root.Val, dfs(root.Right, max_v)+root.Val)
	} else {
		ret = root.Val
	}
	*max_v = max(*max_v, ret)
	return ret
}

func maxPathSum(root *TreeNode) int {
	max_v := -1 * (1 << 30)
	dfs(root, &max_v)
	return max_v
}
