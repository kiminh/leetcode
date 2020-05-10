package main

func findLengthOfLCIS(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	result := make([]int, len(nums))
	result[0] = 1
	for i := 1; i < len(result); i++ {
		result[i] = 1
		if nums[i] > nums[i-1] {
			result[i] = result[i-1] + 1
		}
	}
	max := 0
	for _, v := range result {
		if v > max {
			max = v
		}
	}
	return max

}
