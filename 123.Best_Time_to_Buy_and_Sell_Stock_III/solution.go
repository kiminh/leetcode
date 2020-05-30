package main

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxProfit_helper(prices []int) int {
	if len(prices) <= 1 {
		return 0
	}
	mins := make([]int, len(prices))
	mins[0] = prices[0]
	for i := 1; i < len(mins); i++ {
		if prices[i] < mins[i-1] {
			mins[i] = prices[i]
		} else {
			mins[i] = mins[i-1]
		}
	}
	result := 0
	for i := 1; i < len(prices); i++ {
		if prices[i]-mins[i-1] > result {
			result = prices[i] - mins[i-1]
		}
	}
	return result
}

func maxProfit(prices []int) int {
	dp := make([][]int, len(prices))
	for i, _ := range dp {
		dp[i] = make([]int, len(prices))
	}
	for l := 0; l < len(dp); l++ {
		for r := l; r < len(dp[l]); r++ {
			dp[l][r] = maxProfit_helper(prices[l : r+1])
		}
	}
	//for _, row := range dp {
	//	for _, v := range row {
	//		fmt.Printf("%2d\t", v)
	//	}
	//	fmt.Printf("\n")
	//}
	result := 0
	for spl := 0; spl < len(prices); spl++ {
		result = max(result, dp[0][spl])
		if spl+1 < len(prices) {
			result = max(result, dp[spl+1][len(prices)-1])
			result = max(result, dp[0][spl]+dp[spl+1][len(prices)-1])
		}
	}
	return result
}
