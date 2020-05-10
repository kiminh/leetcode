package main

func missingNumber(nums []int) int {
	var res int = 0
	for _, v := range nums {
		res ^= v
	}
	for i := 0; i <= len(nums); i++ {
		res ^= i
	}
	return res
}
