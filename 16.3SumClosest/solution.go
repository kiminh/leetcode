package main

func threeSumClosest(nums []int, target int) int {
	m := []int{}
	for i := 0; i < len(nums); i++ {
		for t := i + 1; t < len(nums); t++ {
			tar := target - (nums[i] + nums[t])
			if _, found := m[tar]; found {

			}
		}
	}

}
