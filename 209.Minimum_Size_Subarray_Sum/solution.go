package main

func minSubArrayLen(s int, nums []int) int {
	result := 1 << 31
	dp := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		for t := i; t >= i-result+1 && t >= 0; t-- {
			dp[t] += nums[i]
			if dp[t] >= s {
				if i-t+1 < result {
					result = i - t + 1
				}
			}
		}
	}
	if result == 1<<31 {
		return 0
	}
	return result
}

func minSubArrayLen2(s int, nums []int) int {
	result := 1 << 31
	dp := make([][]int, len(nums))
	for i, _ := range dp {
		dp[i] = make([]int, len(nums))
	}
	for col := 0; col < len(nums); col++ {
		for row := col; row >= 0; row-- {
			if row == col {
				dp[row][col] = nums[row]
			} else {
				dp[row][col] = dp[row][col-1] + nums[col]
			}
			if dp[row][col] >= s {
				if col-row+1 < result {
					result = col - row + 1
				}
			}
		}
	}
	//for _, row := range dp {
	//	for _, val := range row {
	//		fmt.Printf("%d\t", val)
	//	}
	//	fmt.Printf("\n")
	//}
	if result == 1<<31 {
		return 0
	}
	return result
}
