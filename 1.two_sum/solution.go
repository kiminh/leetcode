package main

import "sort"

func twoSum_hash(nums []int, target int) []int {
	m := map[int]int{}
	for i, cur := range nums {
		if pre, ok := m[target-cur]; ok {
			return []int{pre, i}
		} else {
			m[cur] = i
		}
	}
	return []int{}
}

func twoSum(nums []int, target int) []int {
	index := map[int]int{}
	for i, v := range nums {
		index[v] = i
	}
	sort.Ints(nums)
	for l, r := 0, len(nums)-1; l <= r; {
		sum := nums[l] + nums[r]
		if sum == target {
			return []int{index[nums[l]], index[nums[r]]}
		} else if sum > target {
			r--
		} else {
			l++
		}
	}
	return []int{}
}
