package main

func permute_notok(nums []int) [][]int {
	all_result := [][]int{[]int{}}
	if len(nums) == 1 {
		return [][]int{[]int{nums[0]}}
	}
	start := -1
	for _, num := range nums {
		for _, one_all_result := range all_result {
			// 1
			for pos := 0; pos < len(one_all_result); pos++ {
				this_case := make([]int, 0, len(one_all_result)+1)
				this_case = append(this_case, one_all_result[0:pos]...)
				this_case = append(this_case, num)
				this_case = append(this_case, one_all_result[pos:]...)
				if len(this_case) == len(nums) && start == -1 {
					start = len(all_result)
				}
				all_result = append(all_result, this_case)
			}
			// 2
			all_result = append(all_result, append(one_all_result, num))
		}
	}
	return all_result[start:]
}

func permute(nums []int) [][]int {
	all_result := [][]int{[]int{}}
	if len(nums) == 1 {
		return [][]int{[]int{nums[0]}}
	}
	start := -1
	for _, num := range nums {
		for _, one_all_result := range all_result {
			// 1
			for pos := 0; pos < len(one_all_result); pos++ {
				// x x x x x N x x x x x
				this_case := make([]int, 0, len(one_all_result)+1)
				this_case = append(this_case, one_all_result[0:pos]...)
				this_case = append(this_case, num)
				this_case = append(this_case, one_all_result[pos:]...)
				if len(this_case) == len(nums) && start == -1 {
					start = len(all_result)
				}
				all_result = append(all_result, this_case)
			}
			// 2
			last := make([]int, 0, len(one_all_result)+1)
			last = append(last, one_all_result...)
			last = append(last, num)
			all_result = append(all_result, last)
		}
	}
	return all_result[start:]
}
