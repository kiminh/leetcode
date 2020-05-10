package main

import "fmt"

func setup(is_prime []bool, max_prime_divisor []int) bool {
	if len(is_prime) != len(max_prime_divisor) {
		return false
	}
	length := len(is_prime)
	for i := 0; i < length; i++ {
		is_prime[i] = true
		max_prime_divisor[i] = -1
	}
	if length <= 2 {
		return true
	}
	is_prime[2] = true
	for i := 2; i <= length-1; i++ {
		if is_prime[i] {
			for mul := 2; mul*i <= length-1; mul++ {
				is_prime[mul*i] = false
				max_prime_divisor[i*mul] = i
			}
		}
	}
	return true
}

func minSteps(n int) int {
	dp := make([]int, n+1)
	is_prime := make([]bool, n+1)
	max_prime_divisor := make([]int, n+1)
	setup(is_prime, max_prime_divisor)
	dp[1] = 0
	for i := 2; i <= n; i++ {
		dp[i] = i
		fmt.Printf("init  dp[%d] = %d\n", i, i)
		if !is_prime[i] {
			// 如果分解为2个素数之乘积的话，例如M*N(5*11),那么先累积M后拷贝复制N-1次
			// 和先累积N后拷贝复制M-1次的结果是一样的，操作步数都是M+N
			// 但是如果又一个因子不是素数，例如如果M不是素数，那么dp[M]肯定是小于M本身的。
			// 这样就能让整个结果变小。
			//mpd := max_prime_divisor[i] //最大素数约数, 例如5 * 12
			//dp[i] = dp[i/mpd] + mpd
			for A := 2; A*A <= i; A++ {
				if i%A == 0 {
					B := i / A
					fmt.Printf("\tcheck dp[%d] = dp[%d] + %d = %d + %d = %d\n", i, A, B, dp[A], B, dp[A]+B)
					if dp[A]+B < dp[i] {
						dp[i] = dp[A] + B
					}
					fmt.Printf("\tcheck dp[%d] = %d + dp[%d] = %d + %d = %d\n", i, A, B, A, dp[B], A+dp[B])
					if A+dp[B] < dp[i] {
						dp[i] = A + dp[B]
					}
				}
			}
		}
	}
	return dp[n]
}
