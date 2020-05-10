package main

func is_sub_seq(text1 string, text2 string) bool {
	next := 0
	for pos := 0; pos < len(text1); pos++ {
		if next < len(text2) {
			if text1[pos] == text2[next] {
				next++
			}
		}
	}
	return len(text2) == next
}

func numMatchingSubseq(S string, words []string) int {
	result := 0
	for _, str := range words {
		if is_sub_seq(S, str) {
			result++
		}
	}
	return result
}
