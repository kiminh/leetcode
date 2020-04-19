package main

func numTrees(n int) int {
	vec := make([]int, n+1)
	vec[0] = 1
	for i := 1; i <= n; i++ {
		vec[i] = 0
		for root := 1; root <= i; root++ {
			vec[i] += vec[root-1] * vec[i-root]
		}
	}
	return vec[len(vec)-1]
}
