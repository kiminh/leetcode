package main

import "fmt"

const INF int = 1 << 31

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func minSwap(A []int, B []int) int {
	if len(A) == 0 || len(B) == 0 {
		return 0
	}
	ends_with_AB := make([]int, len(A))
	ends_with_BA := make([]int, len(A))
	ends_with_AB[0] = 0
	ends_with_BA[0] = 1
	for i := 1; i < len(A); i++ {
		ends_with_AB[i] = INF
		ends_with_BA[i] = INF
		// up ends_with_AB
		if A[i] > A[i-1] && B[i] > B[i-1] {
			ends_with_AB[i] = min(ends_with_AB[i], ends_with_AB[i-1]+0)
		}
		if A[i] > B[i-1] && B[i] > A[i-1] {
			ends_with_AB[i] = min(ends_with_AB[i], ends_with_BA[i-1]+0)
		}
		// update ends_with_BA
		if B[i] > A[i-1] && A[i] > B[i-1] {
			ends_with_BA[i] = min(ends_with_BA[i], ends_with_AB[i-1]+1)
		}
		if B[i] > B[i-1] && A[i] > A[i-1] {
			ends_with_BA[i] = min(ends_with_BA[i], ends_with_BA[i-1]+1)
		}
	}
	for i := 0; i < len(A); i++ {
		fmt.Printf("%3d ", ends_with_AB[i])
	}
	fmt.Printf("\n")
	for i := 0; i < len(A); i++ {
		fmt.Printf("%3d ", ends_with_BA[i])
	}
	fmt.Printf("\n")
	return min(ends_with_AB[len(A)-1], ends_with_BA[len(A)-1])
}
