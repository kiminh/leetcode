package main

func check(s string, l, r int) bool {
	for l < r {
		if s[l] != s[r] {
			return false
		}
		l++
		r--
	}
	return true
}

func partition(s string) [][]string {
	if len(s) == 0 {
		return [][]string{}
	}
	if len(s) == 1 {
		return [][]string{{s}}
	}
	dp := make([][][]string, len(s))
	for i, _ := range dp {
		dp[i] = [][]string{}
	}
	dp[0] = append(dp[0], []string{s[0:1]})
	for i := 1; i < len(dp); i++ {
		if check(s, 0, i) {
			temp := []string{s[0 : i+1]}
			dp[i] = append(dp[i], temp)
		}
		for t := i; t > 0; t-- {
			if check(s, t, i) {
				for _, v := range dp[t-1] {
					temp := []string{}
					temp = append(temp, v...)
					temp = append(temp, s[t:i+1])
					dp[i] = append(dp[i], temp)
				}
			}
		}
	}
	//for ia, a := range dp {
	//	for _, b := range a {
	//		fmt.Printf("[%2d] %v\n", ia, b)
	//	}
	//}
	return dp[len(dp)-1]
}
