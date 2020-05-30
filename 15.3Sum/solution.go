package main

import "sort"

type cnt_t int

func threeSum(nums []int) [][]int {
	if len(nums) < 3 {
		return [][]int{}
	}
	result := [][]int{}
	sort.Ints(nums)
	m := map[int]cnt_t{}
	for i := 0; i < len(nums); i++ {
		m_t := map[int]cnt_t{}
		for t := i + 1; t < len(nums); t++ {
			target := -1 * (nums[i] + nums[t])
			if cnt, found := m[target]; found && cnt == 1 {
				if cnt_t, found_t := m_t[nums[t]]; found_t && cnt_t == 1 {
					result = append(result, []int{target, nums[i], nums[t]})
				}
			}
			m_t[nums[t]]++
		}
		m[nums[i]]++
	}
	return result
}
