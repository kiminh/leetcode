package main

func min(vals ...int) int {
	if len(vals) == 0 {
		panic("invalid param")
	}
	res := vals[0]
	for _, v := range vals {
		if v < res {
			res = v
		}
	}
	return res
}

func numSquares(n int) int {
	res := make([]int, n+1)
	res[0] = 0
	res[1] = 1
	for t := 2; t <= n; t++ {
		min_cnt := t
		for s := 1; s*s <= t; s++ {
			min_cnt = min(min_cnt, 1+res[t-s*s])
		}
		res[t] = min_cnt
	}
	return res[len(res)-1]

}
