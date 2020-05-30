package main

import (
	"strconv"
	"strings"
)

func restoreIpAddresses(s string) []string {
	result := []string{}
	if len(s) > 12 {
		return []string{}
	}
	dp := make([][][]int, len(s)+1)
	for i, _ := range dp {
		dp[i] = [][]int{}
	}
	dp[0] = append(dp[0], []int{})
	for l := 1; l < len(dp); l++ {
		for rob := 0; l-rob > 0 && rob < 3; rob++ {
			str := s[l-rob-1 : l]
			if len(str) > 1 && str[0] == '0' {
				continue
			}
			if num, ok := strconv.Atoi(str); ok == nil && num <= 255 {
				for _, v := range dp[l-rob-1] {
					one_ans := []int{}
					one_ans = append(one_ans, v...)
					one_ans = append(one_ans, num)
					dp[l] = append(dp[l], one_ans)
				}
			}
		}
	}
	for _, v := range dp[len(dp)-1] {
		if len(v) == 4 {
			temp := make([]string, 4)
			for i, num := range v {
				temp[i] = strconv.Itoa(num)
			}
			result = append(result, strings.Join(temp, "."))
		}
	}
	return result

}
