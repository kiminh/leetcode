package main

import (
	"sort"
)

func max(vals ...int) int {
	if len(vals) == 0 {
		panic("fail")
	}
	max_val := vals[0]
	for _, v := range vals {
		if max_val < v {
			max_val = v
		}
	}
	return max_val
}
func largestDivisibleSubset(nums []int) []int {
	if len(nums) == 0 {
		return []int{}
	}
	var res []int
	sort.Ints(nums)
	helper := make([]int, len(nums))
	prev := make([]int, len(nums))
	helper[0] = 1
	max_helper_index := 0
	prev[0] = -1
	for i := 1; i < len(nums); i++ {
		max_set_size := 1
		prev[i] = -1
		for k := i - 1; k >= 0; k-- {
			if nums[i]%nums[k] == 0 {
				if 1+helper[k] > max_set_size {
					prev[i] = k
					max_set_size = 1 + helper[k]
				}
			}
		}
		helper[i] = max_set_size
		if helper[i] > helper[max_helper_index] {
			max_helper_index = i
		}
	}
	for max_helper_index != -1 {
		res = append(res, nums[max_helper_index])
		max_helper_index = prev[max_helper_index]
	}
	return res
}
