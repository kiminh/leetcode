package main

func find132pattern(nums []int) bool {
	result := false
	if len(nums) < 3 {
		return false
	}
	for i := 2; i < len(nums); i++ {
		if nums[i] < nums[i-1] && nums[i] > nums[i-2] {
			return true
		}
	}
	return result
}
