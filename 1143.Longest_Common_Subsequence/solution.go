package main

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func longestCommonSubsequence(A string, f string) int {
	dp := make([][]int, len(f))
	for i, _ := range dp {
		dp[i] = make([]int, len(A))
	}
	for t := 0; t < len(A); t++ {
		if A[t] == f[0] || (t != 0 && dp[0][t-1] != 0) {
			dp[0][t] = 1
		}
	}
	for i := 0; i < len(f); i++ {
		if f[i] == A[0] || (i != 0 && dp[i-1][0] != 0) {
			dp[i][0] = 1
		}
	}
	for i := 1; i < len(f); i++ {
		for t := 1; t < len(A); t++ {
			if f[i] == A[t] {
				dp[i][t] = dp[i-1][t-1] + 1
			} else {
				dp[i][t] = max(dp[i][t-1], dp[i-1][t])
			}
		}
	}
	return dp[len(f)-1][len(A)-1]

}
