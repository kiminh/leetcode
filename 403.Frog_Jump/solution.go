package main

func canCross(stones []int) bool {
	m := make([][]int, len(stones))
	for i, _ := range m {
		m[i] = make([]int, len(stones))
	}
	if stones[1]-stones[0] != 1 {
		return false
	}
	m[1][0] = 1
	for pos := 2; pos < len(stones); pos++ {
		for from_prev := pos - 1; from_prev >= 0; from_prev-- {
			diff := stones[pos] - stones[from_prev]
			for check := from_prev - 1; check >= 0; check-- {
				prev_step := m[from_prev][check]
				if prev_step != 0 && (prev_step == diff ||
					prev_step == diff+1 || prev_step == diff-1) {
					m[pos][from_prev] = diff
					break
				}
			}
		}
	}
	for _, v := range m[len(stones)-1] {
		if v != 0 {
			return true
		}
	}
	return false
}
