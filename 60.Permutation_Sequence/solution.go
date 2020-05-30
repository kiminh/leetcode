package main

func next_permutation(nums []byte) {
	if len(nums) == 1 {
		return
	}
	inc_point := len(nums) - 1
	for ; inc_point > 0 && nums[inc_point] <= nums[inc_point-1]; inc_point-- {
	}
	if inc_point > 0 {
		for m := len(nums) - 1; m >= inc_point; m-- {
			if nums[m] > nums[inc_point-1] {
				nums[inc_point-1], nums[m] = nums[m], nums[inc_point-1]
				break
			}
		}
	}
	for l, r := inc_point, len(nums)-1; l < r; l, r = l+1, r-1 {
		nums[l], nums[r] = nums[r], nums[l]
	}
}

func getPermutation(n int, k int) string {
	result := make([]byte, n)
	for i := 0; i < len(result); i++ {
		result[i] = byte(i) + '1'
	}
	for k-1 > 0 {
		next_permutation(result)
		k--
	}
	return string(result)
}
