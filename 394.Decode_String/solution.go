package main

import (
	"fmt"
	"strconv"
)

type Stack struct {
	vec []byte
}

func (s *Stack) Push(d byte) {
	s.vec = append(s.vec, d)
}

func (s *Stack) Init() {
	s.vec = []byte{}
}

func (s *Stack) Empty() bool {
	return len(s.vec) == 0
}

func (s *Stack) Pop() byte {
	top := s.vec[len(s.vec)-1]
	s.vec = s.vec[:len(s.vec)-1]
	return top
}

func (s *Stack) String() string {
	return string(s.vec)
}

func (s *Stack) Top() byte {
	top := s.vec[len(s.vec)-1]
	return top
}

func decodeString(s string) string {
	s = fmt.Sprintf("1[%s]", s)
	var sta Stack
	for pos := 0; pos < len(s); pos++ {
		ch := s[pos]
		if ch >= '0' && ch <= '9' {
			sta.Push(ch)
		} else if ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' {
			sta.Push(ch)
		} else if ch == '[' {
			sta.Push(ch)
		} else if ch == ']' {
			var temp string
			for sta.Top() != '[' {
				temp = string([]byte{sta.Pop()}) + temp
			}
			sta.Pop()
			var cnt string
			for !sta.Empty() && sta.Top() >= '0' && sta.Top() <= '9' {
				cnt = string([]byte{sta.Pop()}) + cnt
			}
			digit_cnt, _ := strconv.Atoi(cnt)
			for tt := 0; tt < digit_cnt; tt++ {
				for ttt := 0; ttt < len(temp); ttt++ {
					sta.Push(temp[ttt])
				}
			}
		}
	}
	return sta.String()
}
