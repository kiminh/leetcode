package main

func min(vals ...int) int {
	if len(vals) == 0 {
		panic("fail")
	}
	min_val := vals[0]
	for _, v := range vals {
		if min_val > v {
			min_val = v
		}
	}
	return min_val
}

func coinChange(coins []int, amount int) int {
	res := make([]int, amount+1)
	res[0] = 0
	for i := 1; i <= amount; i++ {
		res[i] = amount + 1
		for _, c := range coins {
			if c <= i && (res[i-c] != -1) {
				res[i] = min(res[i], 1+res[i-c])
			}
		}
	}
	if res[len(res)-1] == amount+1 {
		return -1
	}
	return res[len(res)-1]

}
