package list

type ListNode struct {
	Val  int
	Next *ListNode
}

type List struct {
	root ListNode
	len  int
}

type Interface interface {
	Init(n *ListNode) Interface
	Head() *ListNode
	Root() *ListNode
	Last() *ListNode
	PushBack(data ...int)
	MoveNodeToBack(n *ListNode)
	LinkHeadToBack(n *ListNode)
	Len() int
}

type HeadList []Interface

func (l *List) Init(n *ListNode) Interface {
	l.len = 0
	l.root.Next = n
	return l
}

func (l *List) Head() *ListNode {
	return l.root.Next
}

func (l *List) Root() *ListNode {
	return &l.root
}

func (l *List) Last() *ListNode {
	pos := &l.root
	for pos.Next != nil {
		pos = pos.Next
	}
	return pos
}

func (l *List) pushBack(data int) {
	l.Last().Next = &ListNode{data, nil}
}

func (l *List) PushBack(data ...int) {
	for _, v := range data {
		l.pushBack(v)
	}
}

func (l *List) MoveNodeToBack(n *ListNode) {
	l.LinkHeadToBack(n)
	n.Next = nil
}

func (l *List) LinkHeadToBack(n *ListNode) {
	l.Last().Next = n
}

func (l *List) Len() int {
	if l.root.Next == nil {
		return 0
	}
	pos, lenght := l.root.Next, 0
	for ; pos != nil; pos, lenght = pos.Next, lenght+1 {
	}
	return lenght
}

func (l *List) AfterSortRemoveDuplicate() *List {
	if l.Head() == nil || l.Head().Next == nil {
		return l
	}
	pos := l.Head()
	for pos != nil {
		for pos.Next != nil && pos.Next.Val == pos.Val {
			pos.Next = pos.Next.Next
		}
		pos = pos.Next
	}
	return l
}

func NewList(lst *ListNode) Interface {
	return new(List).Init(lst)
}

func Merge(la, lb Interface) Interface {
	ha, hb := la.Head(), lb.Head()
	if ha == nil {
		return NewList(hb)
	} else if hb == nil {
		return NewList(ha)
	}
	res := NewList(nil)
	for ha != nil && hb != nil {
		if ha.Val < hb.Val {
			target := ha
			ha = ha.Next
			res.MoveNodeToBack(target)
		} else {
			target := hb
			hb = hb.Next
			res.MoveNodeToBack(target)
		}
	}
	var last *ListNode
	if ha != nil {
		last = ha
	} else {
		last = hb
	}
	res.LinkHeadToBack(last)
	return res
}

func mergeHelper(hlist HeadList) HeadList {
	if len(hlist) < 2 {
		return hlist
	}
	res := HeadList{}
	for len(hlist) != 0 {
		one := hlist[0]
		hlist = hlist[1:]
		if len(hlist) == 0 {
			res = append(res, one)
		} else {
			two := hlist[0]
			hlist = hlist[1:]
			res = append(res, Merge(one, two))
		}
	}
	return res
}

func Rotate(l *List, k int) *List {
	length := l.Len()
	if length == 0 {
		return l
	}
	k = k % l.Len()
	if k == 0 {
		return l
	}
	prev_cnt := length - k
	pos := &l.root
	for prev_cnt > 0 {
		pos = pos.Next
		prev_cnt--
	}
	l.Last().Next = l.Head()
	l.root.Next = pos.Next
	pos.Next = nil
	return l
}

func Sort(l Interface) Interface {
	if l == nil || l.Head() == nil || l.Head().Next == nil {
		// nil; zero node; one node
	}
	// at least two node
	hlist := HeadList{}
	pos := l.Head()
	for pos != nil {
		temp := pos
		pos = pos.Next
		temp.Next = nil
		hlist = append(hlist, NewList(temp))
	}
	for len(hlist) != 1 {
		hlist = mergeHelper(hlist)
	}
	return hlist[0]
}

func sortList(head *ListNode) *ListNode {
	l := new(List).Init(head)
	l = Sort(l)
	return l.Head()
}

func ReverseBetween(lst Interface, m int, n int) (bool, *ListNode) {
	if m == n || lst == nil {
		return false, nil
	}
	if m < 0 || m > lst.Len() || n < 0 || n > lst.Len() {
		return false, nil
	}
	var left, right, new_head, new_tail *ListNode
	prev, cur := lst.Root(), lst.Head()
	for cnt := 1; cnt <= n; cnt++ {
		tprev, tcur := prev, cur
		prev, cur = cur, cur.Next
		if cnt == m {
			left, new_tail = tprev, tcur
		} else if cnt == n {
			right, new_head = tcur.Next, tcur
		}
		if cnt > m && cnt <= n {
			tcur.Next = tprev
		}
	}
	left.Next = new_head
	new_tail.Next = right
	return true, new_tail
}
