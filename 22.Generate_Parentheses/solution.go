package main

import "fmt"

func generateParenthesis(n int) []string {
	dp := make([][]string, n+1)
	dp[0] = []string{""}
	for l := 1; l < len(dp); l++ {
		dp[l] = []string{}
		for t := 0; t <= l-1; t++ {
			for _, left := range dp[t] {
				for _, right := range dp[l-t-1] {
					dp[l] = append(dp[l], fmt.Sprintf("(%s)%s", left, right))
				}
			}
		}
	}
	return dp[len(dp)-1]
}
