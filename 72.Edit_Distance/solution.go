package main

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minDistance(word1 string, word2 string) int {
	if len(word1) == 0 {
		return len(word2)
	}
	if len(word2) == 0 {
		return len(word1)
	}
	dp := make([][]int, len(word1)+1)
	for i, _ := range dp {
		dp[i] = make([]int, len(word2)+1)
	}
	dp[0][0] = 0
	for col := 1; col < len(dp[0]); col++ {
		dp[0][col] = col
	}
	for row := 1; row < len(dp); row++ {
		dp[row][0] = row
	}
	for i := 1; i < len(dp); i++ {
		for j := 1; j < len(dp[i]); j++ {
			dp[i][j] = 1 << 31
			if word1[i-1] == word2[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = min(dp[i][j], dp[i-1][j]+1)
				dp[i][j] = min(dp[i][j], dp[i][j-1]+1)
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1)
			}
		}
	}
	return dp[len(dp)-1][len(dp[0])-1]
}
