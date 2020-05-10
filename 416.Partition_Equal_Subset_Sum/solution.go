package main

func canPartition(nums []int) bool {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	if sum%2 != 0 {
		return false
	}
	target := sum / 2
	result := make([][]bool, len(nums))
	for i := 0; i < len(result); i++ {
		result[i] = make([]bool, target+1)
	}
	for row := 0; row < len(result); row++ {
		for val := 1; val <= target; val++ {
			if nums[row] == val {
				// satisfy by self
				result[row][val] = true
				continue
			}
			if row != 0 && result[row-1][val] {
				// satisfy by i-1
				result[row][val] = true
				continue
			}
			if nums[row] < val && row != 0 && result[row-1][val-nums[row]] {
				result[row][val] = true
				continue
			}
		}
	}
	return result[len(result)-1][len(result[0])-1]

}
