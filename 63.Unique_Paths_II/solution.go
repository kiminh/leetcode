package main

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	dp := make([][]int, len(obstacleGrid))
	for i, _ := range dp {
		dp[i] = make([]int, len(obstacleGrid[i]))
	}
	if obstacleGrid[0][0] != 1 {
		dp[0][0] = 1
	}
	for row := 0; row < len(dp); row++ {
		for col := 0; col < len(dp[row]); col++ {
			if obstacleGrid[row][col] == 1 {
				continue
			}
			if row > 0 && obstacleGrid[row-1][col] != 1 {
				dp[row][col] += dp[row-1][col]
			}
			if col > 0 && obstacleGrid[row][col-1] != 1 {
				dp[row][col] += dp[row][col-1]
			}
		}
	}
	//for _, v := range dp {
	//	fmt.Println(v)
	//}
	return dp[len(dp)-1][len(dp[0])-1]
}
