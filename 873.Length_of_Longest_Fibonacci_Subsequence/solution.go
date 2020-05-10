package main

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func lenLongestFibSubseq(A []int) int {
	dp := make([]int, len(A))
	max_dp := 0
	dp[0] = 1
	m := map[int]int{A[0]: 0}
	for i := 1; i < len(dp); i++ {
		sum := A[i]
		dp[i] = 1
		mm := map[int]int{}
		for t := 0; t < i; t++ {
			// A[t], sum-A[t]
			if idx, ok := mm[sum-A[t]]; ok {
				dp[i] = max(dp[i], 3)
				diff := A[t] - (sum - A[t])
				if iidx, ook := m[diff]; ook && iidx < idx {
					dp[i] += dp[iidx]
				}
			}
			mm[A[t]] = t
		}
		m[A[i]] = i
		max_dp = max(max_dp, dp[i])
	}
	return max_dp

}
