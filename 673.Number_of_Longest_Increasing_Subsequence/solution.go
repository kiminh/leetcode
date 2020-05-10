package main

func findNumberOfLIS(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	result_len := make([]int, len(nums))
	result_cnt := make([]map[int]int, len(nums))
	for i, _ := range result_cnt {
		result_cnt[i] = map[int]int{}
	}
	result_len[0] = 1
	result_cnt[0] = map[int]int{1: 1}
	for i := 1; i < len(result_len); i++ {
		result_len[i] = 1
		result_cnt[i] = map[int]int{1: 1}
		for t := i - 1; t >= 0; t-- {
			if nums[i] > nums[t] {
				try_len := result_len[t] + 1
				result_cnt[i][try_len] += result_cnt[t][result_len[t]]
				if try_len > result_len[i] {
					result_len[i] = try_len
				}
			}
		}
	}
	longest := 1
	for _, v := range result_len {
		if v > longest {
			longest = v
		}
	}

	res := 0
	for _, v := range result_cnt {
		for k, vv := range v {
			if k == longest {
				res += vv
			}
		}
	}
	return res
}
