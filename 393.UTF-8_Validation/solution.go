package main

func validUtf8(data []int) bool {
	for i := 0; i < len(data); {
		first := data[i]
		var test_n int = 0
		if (first >> 3) == 0x1e { //0B11110
			test_n = 3
		} else if (first >> 4) == 0xe { //0B1110
			test_n = 2
		} else if (first >> 5) == 0x6 { //0B110
			test_n = 1
		} else if (first >> 7) == 0x0 {
			test_n = 0
		} else {
			return false
		}
		if test_n != 0 && i == len(data)-1 {
			return false
		}
		for t := 1; t <= int(test_n); t++ {
			if data[i+t]>>6 != 0x2 { //0b10
				return false
			}
		}
		i += test_n + 1
	}
	return true
}
