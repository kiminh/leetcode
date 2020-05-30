package main
import (
	"sort"
)

func subsetsWithDup(nums []int) [][]int {
	result := [][]int{[]int{}}
	sort.Ints(nums)
	last_head := 0
	for in, v := range nums {
		var i int
		if in == 0 || v != nums[in-1] {
			i = 0
		} else {
			i = last_head
		}
		temp := [][]int{}
		for i < len(result) {
			set := result[i]
			temp = append(temp, append([]int{v}, set...))
			i++
		}
		last_head = len(result)
		result = append(result, temp...)
	}
	return result
}