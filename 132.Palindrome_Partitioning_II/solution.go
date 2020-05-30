package main

func check(s string, l, r int) bool {
	for l < r {
		if s[l] != s[r] {
			return false
		}
		l++
		r--
	}
	return true
}

func minCut(s string) int {
	if len(s) <= 1 {
		return 0
	}
	dp := make([]int, len(s))
	dp[0] = 0
	if s[1] == s[0] {
		dp[1] = 0
	} else {
		dp[1] = 1
	}
	for pos := 2; pos < len(dp); pos++ {
		dp[pos] = dp[pos-1] + 1
		if check(s, 0, pos) {
			// checkout [0, pos] first
			dp[pos] = 0
			continue
		}
		for i := pos - 1; i > 0; i-- {
			if check(s, i, pos) && dp[i-1]+1 < dp[pos] {
				dp[pos] = dp[i-1] + 1
			}
			if dp[pos] == 0 {
				break
			}
		}
	}
	return dp[len(dp)-1]
}
