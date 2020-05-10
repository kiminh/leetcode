package main

func findLength(A []int, B []int) int {
	results := make([][]int, len(A))
	for i, _ := range results {
		results[i] = make([]int, len(B))
	}
	for i, _ := range A {
		for j, _ := range B {
			if A[i] == B[j] {
				results[i][j] = 1
				if i > 0 && j > 0 && results[i-1][j-1] > 0 {
					results[i][j] = results[i-1][j-1] + 1
				}
			}
		}
	}
	max := 0
	for i, _ := range A {
		for j, _ := range B {
			if results[i][j] > max {
				max = results[i][j]
			}
		}
	}
	return max

}
