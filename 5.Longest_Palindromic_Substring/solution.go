package main

import "fmt"

const debug bool = true

func longestPalindrome(s string) string {
	dp := make([][]bool, len(s))
	for i := 0; i < len(s); i++ {
		dp[i] = make([]bool, len(s))
	}
	// i == j
	for ij := 0; ij < len(s); ij++ {
		dp[ij][ij] = true
	}
	// j = i + 1
	for i := 0; i < len(s)-1; i++ {
		if s[i] == s[i+1] {
			dp[i][i+1] = true
		}
	}
	for j := 2; j < len(s); j++ {
		for i := j - 1; i >= 0; i-- {
			if s[i] == s[j] && dp[i+1][j-1] {
				dp[i][j] = true
			}
		}
	}
	if debug {
		for _, v := range dp {
			for _, val := range v {
				if val {
					fmt.Printf("1\t")
				} else {
					fmt.Printf("0\t")
				}
			}
			fmt.Printf("\n")
		}
	}
	max_len := 0
	max_result := ""
	for i := 0; i < len(s); i++ {
		for j := i; j < len(s); j++ {
			if dp[i][j] && j-i+1 > max_len {
				max_len = j - i + 1
				max_result = s[i : j+1]
			}
		}
	}
	return max_result
}
