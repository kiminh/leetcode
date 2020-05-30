package main

func nextPermutation(nums []int) {
	if len(nums) == 1 {
		return
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
	l, r := i, len(nums)-1
	for l < r {
		nums[l], nums[r] = nums[r], nums[l]
		l++
		r--
	}
}
