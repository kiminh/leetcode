package main

type Pair struct {
	A int
	B int
}

func insert(s *map[Pair]bool, A int, B int) {
	if A < B {
		(*s)[Pair{A, B}] = true
	} else {
		(*s)[Pair{B, A}] = true
	}
}

func exists(s *map[Pair]bool, A int, B int) bool {
	if A < B {
		if _, ok := (*s)[Pair{A, B}]; ok {
			return true
		}
	} else {
		if _, ok := (*s)[Pair{B, A}]; ok {
			return true
		}
	}
	return false
}

func findPairs(nums []int, k int) int {
	if k < 0 {
		return 0
	}
	set := map[Pair]bool{}
	result := 0
	m := map[int]bool{}
	for _, v := range nums {
		if _, ok := m[v+k]; ok {
			if !exists(&set, v, v+k) {
				result++
				insert(&set, v, v+k)
			}
		}
		if _, ok := m[v-k]; ok {
			if !exists(&set, v, v-k) {
				result++
				insert(&set, v, v-k)
			}
		}
		m[v] = true
	}
	return result
}
