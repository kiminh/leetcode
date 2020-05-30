package main

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func longestConsecutive(nums []int) int {
	exists := map[int]int{}
	for _, num := range nums {
		exists[num] = 1
	}
	max_l := 0
	for num, _ := range exists {
		walk_num := num
		_, ok := exists[walk_num]
		for ok {
			walk_num++
			_, ok = exists[walk_num]
		}
		if walk_num-num > max_l {
			max_l = walk_num - num
		}
	}
	return max_l

}
