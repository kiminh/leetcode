package main

func max(vals ...int) int {
	if len(vals) == 0 {
		panic("fail")
	}
	maxvalue := vals[0]
	for _, v := range vals {
		if maxvalue < v {
			maxvalue = v
		}
	}
	return maxvalue
}
func min(vals ...int) int {
	if len(vals) == 0 {
		panic("fail")
	}
	maxvalue := vals[0]
	for _, v := range vals {
		if maxvalue > v {
			maxvalue = v
		}
	}
	return maxvalue
}

func maxProduct(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	max_res := make([]int, len(nums))
	min_res := make([]int, len(nums))
	max_res[0] = nums[0]
	min_res[0] = nums[0]
	for i := 1; i < len(max_res); i++ {
		max_res[i] = max(nums[i], nums[i]*max_res[i-1], nums[i]*min_res[i-1])
		min_res[i] = min(nums[i], nums[i]*max_res[i-1], nums[i]*min_res[i-1])
	}
	max_max_res := max_res[0]
	for _, v := range max_res {
		if v > max_max_res {
			max_max_res = v
		}
	}
	return max_max_res
}
