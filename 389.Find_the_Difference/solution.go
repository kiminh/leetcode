package main

func findTheDifference(s string, t string) byte {
	var res rune = 0
	for _, v := range s {
		res ^= v
	}
	for _, v := range t {
		res ^= v
	}
	return byte(res)
}
