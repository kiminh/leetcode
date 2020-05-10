package main

func min(vals ...int) int {
	min_v := vals[0]
	for i := 1; i < len(vals); i++ {
		if vals[i] < min_v {
			min_v = vals[i]
		}
	}
	return min_v
}
func integerReplacement(n int) int {
	if n == 1 {
		return 0
	}
	if n%2 == 1 {
		return min(
			integerReplacement((n+1)/2)+1,
			integerReplacement((n-1)/2)+1) + 1
	} else {
		return integerReplacement(n/2) + 1
	}
}

func integerReplacement2(n int) int {
	if n == 1 {
		return 0
	}
	cnt := 0
	for n != 1 {
		if n%2 == 0 {
			n >>= 1
		} else {
			n -= 1
		}
		cnt++
	}
	return cnt
}

func integerReplacement_dp(n int) int {
	if n == 1 {
		return 0
	}
	var n_t int = n
	if n%2 == 1 {
		n_t = n + 1
	} else {
		return integerReplacement_dp(n/2) + 1

	}
	res := make([]int, n_t+1)
	res[0] = 0
	res[1] = 0
	if n == 2 {
		return 1
	}
	res[2] = 1
	if n == 3 {
		return 2
	}
	res[3] = 2
	for i := 4; i <= n_t; i += 2 {
		res[i] = res[i/2] + 1
		res[i-1] = min(res[i-1-1], res[i]) + 1
	}
	return res[n]
}
