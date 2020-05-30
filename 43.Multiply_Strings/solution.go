package main

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func add(a, b string) string {
	if a == "0" {
		return b
	}
	if b == "0" {
		return a
	}
	var result string
	inc := false
	i := 0
	for ; i < min(len(a), len(b)); i++ {
		sum := (a[i] - '0') + (b[i] - '0')
		if inc {
			sum += 1
		}
		if sum < 10 {
			result += string([]byte{sum + '0'})
			inc = false
		} else {
			result += string([]byte{sum%10 + '0'})
			inc = true
		}
	}

	if len(a) != len(b) {
		var remain string
		if i == len(a) {
			remain = b[i:]
		} else {
			remain = a[i:]
		}
		for k := 0; k < len(remain); k++ {
			sum := remain[k] - '0'
			if inc {
				sum += 1
			}
			if sum < 10 {
				result += string([]byte{sum + '0'})
				inc = false
			} else {
				result += string([]byte{sum%10 + '0'})
				inc = true
			}
		}
		if inc {
			result += "1"
		}
	} else {
		if inc {
			result += "1"
		}
	}
	return result
}

func multiple_helper(num string, ch byte) string {
	var result string
	if ch == '0' {
		return "0"
	}
	inc := 0
	for i := 0; i < len(num); i++ {
		a := num[i]
		mul := (a - '0') * (ch - '0')
		mul += byte(inc)
		if mul < 10 {
			result += string([]byte{mul + '0'})
			inc = 0
		} else {
			result += string([]byte{mul%10 + '0'})
			inc = int(mul) / 10
		}
	}
	if inc > 0 {
		result += string([]byte{byte(inc) + '0'})
	}
	return result
}

func multiply(num1 string, num2 string) string {
	if num1 == "0" || num2 == "0" {
		return "0"
	}
	result := "0"
	temp_num1 := ""
	for pos := len(num1) - 1; pos >= 0; pos-- {
		temp_num1 += string([]byte{num1[pos]})
	}
	num1 = temp_num1
	for i, level := len(num2)-1, 0; i >= 0; i, level = i-1, level+1 {
		sum := multiple_helper(num1, num2[i])
		for z := 0; z < level; z++ {
			sum = "0" + sum
		}
		result = add(result, sum)
	}
	revert := ""
	for i := len(result) - 1; i >= 0; i-- {
		revert += string([]byte{result[i]})
	}
	return revert

}
