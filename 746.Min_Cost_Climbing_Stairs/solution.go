package main

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minCostClimbingStairs(cost []int) int {
	result := make([]int, len(cost))
	result[0] = cost[0]
	result[1] = cost[1]
	for i := 2; i < len(result); i++ {
		result[i] = cost[i] + min(result[i-1], result[i-2])
	}
	return min(result[len(result)-1], result[len(result)-2])
}
