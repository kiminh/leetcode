package main

func isInterleave(A string, B string, C string) bool {
	dp := make([][][]bool, len(A)+1)
	for a := 0; a < len(dp); a++ {
		dp[a] = make([][]bool, len(B)+1)
		for b := 0; b < len(dp[a]); b++ {
			dp[a][b] = make([]bool, len(C)+1)
		}
	}
	// init the edge
	// when c is empty string
	c := 0
	dp[0][0][c] = true

	// when a is empty string
	a := 0
	for b := 0; b < len(dp[a]); b++ {
		// c from 1
		for c := 1; c < len(dp[a][b]); c++ {
			if b == 0 {
				dp[a][b][c] = false
			} else if C[c-1] == B[b-1] && dp[a][b-1][c-1] {
				dp[a][b][c] = true
			}
		}
	}
	// when b is empty string
	// a from 1
	for a := 0; a < len(dp); a++ {
		b := 0
		for c := 1; c < len(dp[a][b]); c++ {
			if a == 0 {
				dp[a][b][c] = false
			} else if C[c-1] == A[a-1] && dp[a-1][b][c-1] {
				dp[a][b][c] = true
			}
		}
	}
	for a := 1; a < len(dp); a++ {
		for b := 1; b < len(dp[a]); b++ {
			for c := 1; c < len(dp[a][b]); c++ {
				// C[:c] == A[:a] + B[:b]
				if C[c-1] == A[a-1] && dp[a-1][b][c-1] {
					dp[a][b][c] = true
				}
				if C[c-1] == B[b-1] && dp[a][b-1][c-1] {
					dp[a][b][c] = true
				}
			}
		}
	}
	return dp[len(A)][len(B)][len(C)]
}
