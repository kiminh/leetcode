package main

type Node [][]int

func combinationSum(candidates []int, target int) [][]int {
	candidates = append([]int{0}, candidates...)
	dp := make([][]Node, target+1)
	for i, _ := range dp {
		dp[i] = make([]Node, len(candidates))
		for t, _ := range dp[i] {
			dp[i][t] = Node{}
		}
	}
	dp[0][0] = Node{{}}
	for vol := 0; vol < len(dp); vol++ {
		for icand := 1; icand < len(dp[vol]); icand++ {
			for k := 0; candidates[icand]*k <= vol; k++ {
				for _, prev_solu := range dp[vol-candidates[icand]*k][icand-1] {
					my_solu := append([]int{}, prev_solu...)
					for kk := 0; kk < k; kk++ {
						my_solu = append(my_solu, candidates[icand])
					}
					dp[vol][icand] = append(dp[vol][icand], my_solu)
				}
			}
		}
	}
	return dp[len(dp)-1][len(dp[0])-1]
}
