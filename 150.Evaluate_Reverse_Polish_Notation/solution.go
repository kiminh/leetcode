package main

import (
	"fmt"
	"strconv"
)

type Stack struct {
	Sta []string
}

func (s *Stack) Init() {
	s.Sta = []string{}
}

func (s *Stack) PopThree() (bool, int, int, string) {
	if len(s.Sta) >= 3 {
		if right, ok1 := strconv.Atoi(s.Sta[len(s.Sta)-1]); ok1 == nil {
			if left, ok2 := strconv.Atoi(s.Sta[len(s.Sta)-2]); ok2 == nil {
				if op := s.Sta[len(s.Sta)-3]; op == "+" || op == "-" || op == "*" || op == "/" {
					s.Pop()
					s.Pop()
					s.Pop()
					return true, right, left, op
				}
			}
		}
	}
	return false, 0, 0, ""
}

func (s *Stack) Empty() bool {
	return len(s.Sta) == 0
}

func (s *Stack) Push(str string) {
	s.Sta = append(s.Sta, str)
}
func (s *Stack) Pop() string {
	top := s.Sta[len(s.Sta)-1]
	s.Sta = s.Sta[:len(s.Sta)-1]
	return top
}
func (s *Stack) Top() string {
	top := s.Sta[len(s.Sta)-1]
	return top
}
func (s *Stack) Size() int {
	return len(s.Sta)
}

func evalRPN2(tokens []string) int {
	var sta Stack
	sta.Init()
	for pos := len(tokens) - 1; pos >= 0 || !sta.Empty(); {
		if pos < 0 && sta.Size() == 1 {
			break
		} else if ok, right, left, op := sta.PopThree(); ok {
			switch op {
			case "+":
				sta.Push(strconv.Itoa(right + left))
			case "-":
				sta.Push(strconv.Itoa(right - left))
			case "*":
				sta.Push(strconv.Itoa(right * left))
			case "/":
				sta.Push(strconv.Itoa(right / left))
			}
		} else if pos >= 0 {
			token := tokens[pos]
			sta.Push(token)
			pos--
		}
	}
	res, _ := strconv.Atoi(sta.Pop())
	return res
}

func evalRPN_a(sta *Stack) int {
	val := sta.Pop()
	if digit, ok := strconv.Atoi(val); ok != nil {
		right := evalRPN_a(sta)
		left := evalRPN_a(sta)
		if val == "+" {
			return left + right
		} else if val == "-" {
			return left - right
		} else if val == "*" {
			return left * right
		} else if val == "/" {
			return left / right
		} else {
			panic(fmt.Sprintf("[%s] is not supported", val))
		}
	} else {
		return digit
	}
}
func evalRPN(tokens []string) int {
	var sta Stack
	sta.Init()
	for _, v := range tokens {
		sta.Push(v)
	}
	return evalRPN_a(&sta)
}
