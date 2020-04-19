package main

func countNumbersWithUniqueDigits(n int) int {
	res := make([]int, n+1)
	res[0] = 1
	for i := 1; i <= n; i++ {
		res[i] = 9
		for k := 0; k < i-1; k++ {
			res[i] *= 9 - k
		}
		res[i] += res[i-1]
	}
	return res[len(res)-1]
}
