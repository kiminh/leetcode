package main

import (
	"sort"
)

type Node [][]int

func combinationSum2(candidates []int, target int) [][]int {
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
			for k := 0; candidates[icand]*k <= vol && k <= 1; k++ {
				for _, prev_solu := range dp[vol-candidates[icand]*k][icand-1] {
					my_solu := append([]int{}, prev_solu...)
					for kk := 0; kk < k; kk++ {
						my_solu = append(my_solu, candidates[icand])
					}
					sort.Ints(my_solu)
					dp[vol][icand] = append(dp[vol][icand], my_solu)
				}
			}
		}
	}
	res := [][]int{}
	s := map[uint32]bool{}
	for _, v := range dp[len(dp)-1][len(dp[0])-1] {
		var sign uint32
		vv := append(v, len(v))
		cnt := 2
		for _, num := range vv {
			sign ^= uint32(num << cnt)
			cnt += 3
		}
		sign += uint32(len(vv))
		if _, ok := s[sign]; !ok {
			res = append(res, v)
			s[sign] = true
		}

	}
	return res
}
