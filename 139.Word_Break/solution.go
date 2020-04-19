package main

import (
	"fmt"
	"strings"
)

func wordBreak(s string, wordDict []string) bool {
	res := make([]bool, len(s))
	for i := 0; i < len(s); i++ {
		current := s[:i+1]
		res[i] = false
		for _, w := range wordDict {
			if strings.HasSuffix(current, w) {
				check_point := len(current) - len(w) - 1
				fmt.Printf("[%s] has [%s] ; check[%d]\n", current, w, check_point)
				if check_point < 0 {
					res[i] = true
				} else if res[check_point] {
					res[i] = true
				}
			}
		}
	}
	return res[len(res)-1]
}
