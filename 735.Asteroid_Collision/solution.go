package main

type Stack struct {
	Vec []int
}

func (s *Stack) Push(d int) {
	s.Vec = append(s.Vec, d)
}

func (s *Stack) Init() {
	s.Vec = []int{}
}

func (s *Stack) Empty() bool {
	return len(s.Vec) == 0
}

func (s *Stack) Pop() int {
	top := s.Vec[len(s.Vec)-1]
	s.Vec = s.Vec[:len(s.Vec)-1]
	return top
}

func (s *Stack) Top() int {
	top := s.Vec[len(s.Vec)-1]
	return top
}
func asteroidCollision(asteroids []int) []int {

	var lsta Stack
	var rsta Stack
	lsta.Init()
	rsta.Init()
	for _, v := range asteroids {
		lsta.Push(v)
	}

	for !lsta.Empty() {
		top := lsta.Pop()
		if top > 0 {
			if rsta.Empty() || rsta.Top() > 0 {
				rsta.Push(top)
			} else if rsta.Top() < 0 {
				rtop := rsta.Pop()
				if -1*rtop > top {
					lsta.Push(rtop)
				} else if -1*rtop < top {
					lsta.Push(top)
				}
			}
		} else {
			if !lsta.Empty() && lsta.Top() > 0 {
				if dd := lsta.Pop(); dd > -1*top {
					lsta.Push(dd)
				} else if dd < -1*top {
					lsta.Push(top)
				}
			} else {
				rsta.Push(top)
			}
		}
	}
	for !rsta.Empty() {
		lsta.Vec = append(lsta.Vec, rsta.Pop())
	}
	return lsta.Vec
}
