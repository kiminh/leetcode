package main

func binary_search(nums []int, target int) int {
	b, e := 0, len(nums)-1
	for b <= e {
		mid := (b + e) / 2
		if nums[mid] == target {
			return mid
		} else if nums[mid] < target {
			b = mid + 1
		} else {
			e = mid - 1
		}
	}
	return -1
}

func searchRange(nums []int, target int) []int {
	if len(nums) == 0 {
		return []int{-1, -1}
	}
	pos := binary_search(nums, target)
	if pos == -1 {
		return []int{-1, -1}
	}
	b, e := pos, pos
	for b >= 0 && nums[b] == target {
		b--
	}
	for e < len(nums) && nums[e] == target {
		e++
	}
	return []int{b + 1, e - 1}

}
