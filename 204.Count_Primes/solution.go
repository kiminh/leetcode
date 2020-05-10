package main

func countPrimes(n int) int {
	result := 0
	is_prime := make([]bool, n+1)
	for i, _ := range is_prime {
		is_prime[i] = true
	}
	if n <= 1 {
		return result
	}
	is_prime[2] = true
	for i := 2; i < n; i++ {
		if is_prime[i] {
			for mul := 2; mul*i < n; mul++ {
				is_prime[mul*i] = false
			}
			result += 1
		}
	}
	return result
}
