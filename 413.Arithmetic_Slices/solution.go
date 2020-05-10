package main

func numberOfArithmeticSlices(A []int) int {
	if len(A) < 3 {
		return 0
	}
	result := make([]int, len(A))
	for i := 2; i < len(A); i++ {
		if A[i]-A[i-1] == A[i-1]-A[i-2] {
			result[i] = result[i-1] + 1
		}
	}
	sum := 0
	for _, v := range result {
		sum += v
	}
	return sum

}
