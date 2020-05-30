package main

func maxProfit_slow(prices []int) int {
	if len(prices) == 1 {
		return 0
	}
	dp := make([]int, len(prices))
	dp[0] = 0
	if prices[1]-prices[0] > 0 {
		dp[1] = prices[1] - prices[0]
	}
	for i := 2; i < len(dp); i++ {
		dp[i] = dp[i-1]
		if prices[i]-prices[0] > dp[i] {
			dp[i] = prices[i] - prices[0]
		}
		for t := i - 1; t > 0; t-- {
			diff := prices[i] - prices[t]
			if diff > 0 && diff+dp[t-1] > dp[i] {
				dp[i] = diff + dp[t-1]
			}
		}
	}
	return dp[len(dp)-1]
}

func maxProfit(prices []int) int {
	diff := make([]int, len(prices)-1)
	for i := 0; i < len(prices)-1; i++ {
		diff[i] = prices[i+1] - prices[i]
	}

}
