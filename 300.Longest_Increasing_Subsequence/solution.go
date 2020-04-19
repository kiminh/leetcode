package main

func max(vals ...int) int {
	if len(vals) == 0 {
		panic("invalid param")
	}
	res := vals[0]
	for _, v := range vals {
		if v > res {
			res = v
		}
	}
	return res
}

func lengthOfLIS(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	res := make([]int, len(nums))
	res[0] = 1
	for i, _ := range nums {
		res[i] = 1
		for l := i - 1; l >= 0; l-- {
			if nums[l] < nums[i] {
				res[i] = max(res[i], 1+res[l])
			}
		}
	}
	max_res := res[0]
	for _, v := range res {
		if v > max_res {
			max_res = v
		}
	}
	return max_res

}
