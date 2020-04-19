package main

func countBits(num int) []int {
	res := make([]int, num+1)
	for i := 0; i <= num; i++ {
		if i%2 == 1 {
			res[i] = res[i-1] + 1
		} else {
			res[i] = res[i/2]
		}
	}
	return res
}
