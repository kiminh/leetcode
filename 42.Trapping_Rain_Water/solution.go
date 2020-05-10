package main

const INF int = 1 << 31

func trap_simulate(height []int) int {
	if len(height) == 0 {
		return 0
	}
	max_height := 0
	min_height := INF
	for _, h := range height {
		if h > max_height {
			max_height = h
		}
		if h < min_height {
			min_height = h
		}
	}
	max_height -= min_height
	for i, _ := range height {
		height[i] -= min_height
	}
	last_same_level := make([][]int, max_height+1)
	for h := 1; h < len(last_same_level); h++ {
		last_same_level[h] = make([]int, len(height))
		last := -1
		for i, _ := range last_same_level[h] {
			if height[i] >= h {
				last_same_level[h][i] = last
				last = i
			}
		}
	}
	dp := make([][]int, max_height+1)
	for irow, _ := range dp {
		dp[irow] = make([]int, len(height))
	}
	for irow, _ := range dp {
		dp[irow][0] = 0
	}
	max := 0
	last_i_max := 0
	for i := 1; i < len(height); i++ {
		dp[0][i] = last_i_max
		for h := 1; h <= height[i]; h++ {
			dp[h][i] += dp[h-1][i]
			if last_same_level[h][i] != -1 {
				dp[h][i] += (i - last_same_level[h][i] - 1)
				if dp[h][i] > max {
					max = dp[h][i]
				}
				last_i_max = dp[h][i]
			} else {
				break
			}
		}
	}
	return max
}

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

func trap(height []int) int {
	result := 0
	for i := 1; i < len(height)-1; i++ {
		left_max_h := 0
		right_max_h := 0
		for pos := i; pos >= 0; pos-- {
			left_max_h = max(left_max_h, height[pos])
		}
		for pos := i; pos < len(height); pos++ {
			right_max_h = max(right_max_h, height[pos])
		}
		result += min(left_max_h, right_max_h) - height[i]
	}
	return result
}
