package main

type pair struct {
	Begin int
	End   int
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
func longestValidParentheses(s string) int {
	if len(s) == 0 {
		return 0
	}
	m := make([]int, len(s))
	m[0] = 0
	for i := 1; i < len(s); i++ {
		if s[i] == ')' {
			if s[i-1] == '(' {
				m[i] = 2
				if i >= 2 {
					m[i] += m[i-2]
				}
			} else {
				if i-m[i-1]-1 >= 0 {
					if s[i-m[i-1]-1] == '(' {
						m[i] = m[i-1] + 2
						if i-m[i-1]-2 >= 0 {
							m[i] += m[i-m[i-1]-2]
						}
					}
				}
			}
		} else {
			m[i] = 0
		}
	}
	max_result := 0
	for _, v := range m {
		if v > max_result {
			max_result = v
		}
	}
	return max_result
}

// not ok; out of memory or time limit exceed
func longestValidParentheses2(s string) int {
	result_max := 0
	m := map[pair]int{}
	for l := 2; l <= len(s); l += 2 {
		for begin := 0; begin+l-1 < len(s); begin++ {
			end := begin + l - 1
			if s[begin] == '(' && s[end] == ')' {
				_, ok := m[pair{begin + 1, end - 1}]
				if l == 2 || ok {
					m[pair{begin, end}] = l
					result_max = max(result_max, m[pair{begin, end}])
					continue
				}
			}
			if l != 2 {
				for spl := begin + 1; spl < end; spl++ {
					if _, ok1 := m[pair{begin, spl}]; ok1 {
						if _, ok2 := m[pair{spl + 1, end}]; ok2 {
							m[pair{begin, end}] = l
							result_max = max(result_max, m[pair{begin, end}])
							break
						}
					}
				}
			}
		}
	}
	return result_max

}
