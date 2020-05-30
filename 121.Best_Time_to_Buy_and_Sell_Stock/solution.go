package main

func maxProfit(prices []int) int {
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
