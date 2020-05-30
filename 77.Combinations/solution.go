package main

func combine(n int, k int) [][]int {
	result := [][]int{[]int{}}
	for i := 1; i <= n; i++ {
		for _, res := range result {
			if len(res) < k {
				one := []int{}
				one = append(one, res...)
				one = append(one, i)
				result = append(result, one)
			}
		}
	}
	result2 := [][]int{}
	for _, v := range result {
		if len(v) == k {
			result2 = append(result2, v)
		}
	}
	return result2
}
