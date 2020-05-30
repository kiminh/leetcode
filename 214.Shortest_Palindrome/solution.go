package main

import "fmt"

const debug bool = false

func longestPalindrome(s string) int {
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
	for j := 0; j < len(s); j++ {
		if dp[0][j] && j+1 > max_len {
			max_len = j+1
		}
	}
	return max_len
}

func longestPalindrome2(s string) int {
	max_len_i_0 := 0
	dp := make([]bool, len(s))
	for j := 0; j < len(s); j++ {
		for i := 0 ; i <= j; i++ {
			dp[i] = false
			if i == j {
				dp[i] = true
			} else if i == j - 1 {
			    if s[i] == s[j] {
				    dp[i] = true
				} 
			} else if s[i] == s[j] && dp[i+1] {
				dp[i] = true
			}
		}
		if dp[0] && j + 1 > max_len_i_0 {
			max_len_i_0 = j + 1
		}
	}
	return max_len_i_0
}


func shortestPalindrome(s string) string {
	max_l := longestPalindrome2(s)
	if debug {
	    fmt.Println(max_l)
	}
	patch := s[max_l:]
	rpatch := ""
	for i := len(patch) - 1; i >= 0; i-- {
		rpatch += string([]byte{patch[i]})
	}
	return rpatch+s
}