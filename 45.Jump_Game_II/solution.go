package main

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func jump(nums []int) int {
	dp := make([]int, len(nums))
	dp[0] = 0
	for i := 1; i < len(dp); i++ {
		dp[i] = 1 << 31
		for p := i - 1; p >= 0; p-- {
			if i-p <= nums[p] {
				dp[i] = min(dp[i], dp[p]+1)
			}
		}
	}
	return dp[len(dp)-1]
}
