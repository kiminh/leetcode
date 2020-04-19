package main

import (
	"math"
)

func subsets(nums []int) [][]int {
	res := [][]int{}
	for i := 0; i < int(math.Pow(2, float64(len(nums)))); i++ {
		tres := []int{}
		for k := 0; k < len(nums); k++ {
			if i&(1<<uint32(k)) != 0 {
				tres = append(tres, nums[k])
			}
		}
		res = append(res, tres)
	}
	return res
}
