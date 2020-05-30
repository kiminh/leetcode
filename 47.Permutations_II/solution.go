package main

import (
	"sort"
)

func nextPermutation(nums []int) bool {
	if len(nums) == 1 {
		return false
	}
	i := len(nums) - 1
	for i > 0 && nums[i-1] >= nums[i] {
		i--
	}
	if i != 0 {
		t := len(nums) - 1
		for t >= i && nums[t] <= nums[i-1] {
			t--
		}
		nums[i-1], nums[t] = nums[t], nums[i-1]
	}
	result := true
	if i == 0 {
		result = false
	}
	l, r := i, len(nums)-1
	for l < r {
		nums[l], nums[r] = nums[r], nums[l]
		l++
		r--
	}
	return result
}

func permuteUnique(nums []int) [][]int {
	result := [][]int{}
	sort.Ints(nums)
	result = append(result, []int{})
	result[len(result)-1] = append(result[len(result)-1], nums...)

	for nextPermutation(nums) {
		result = append(result, []int{})
		result[len(result)-1] = append(result[len(result)-1], nums...)
	}
	return result

}
