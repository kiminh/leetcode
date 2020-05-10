package main

import "fmt"

func findTargetSumWays(nums []int, S int) int {
	if S > 1000 {
		return 0
	}
	result := make([][]int, len(nums))
	for i, _ := range result {
		result[i] = make([]int, 1000*2+1)
	}
	for row := 0; row < len(result); row++ {
		for i := 0; i < len(result[row]); i++ {
			current := nums[row]
			target := -1000 + i
			if row == 0 {
				if target == current {
					result[row][i] += 1
				}
				if target == -1*current {
					result[row][i] += 1
				}
			} else {
				if index := target + current + 1000; index < 1000*2+1 {
					result[row][i] += result[row-1][index]
				}
				if index := target - current + 1000; index > 0 {
					result[row][i] += result[row-1][index]
				}
			}
			if result[row][i] != 0 {
				fmt.Printf("{%4d, %4d} = %4d\n", row, target, result[row][i])
			}
		}
	}
	return result[len(result)-1][S+1000]
}
