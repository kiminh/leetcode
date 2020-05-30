package main

func largestRectangleArea_outofmemory(heights []int) int {
	result := 0
	max_height := 0
	for _, v := range heights {
		if v > max_height {
			max_height = v
		}
	}
	max_behind := make([]int, max_height)
	for bar := 1; bar <= len(heights); bar++ {
		// update max_behind
		for h := 0; h < max_height; h++ {
			if h < heights[bar-1] {
				if bar == 1 {
					max_behind[h] = bar
				} else if max_behind[h] == 0 {
					max_behind[h] = bar
				}
			} else {
				max_behind[h] = 0
			}
			if max_behind[h] != 0 {
				area := (h + 1) * (bar - max_behind[h] + 1)
				if area > result {
					result = area
				}
			}
		}
	}
	return result
}

func largestRectangleArea(heights []int) int {
	most_left_higher := make([]int, len(heights))
	most_right_higher := make([]int, len(heights))
	for i := 0; i < len(heights); i++ {
		v := heights[i]
		for p := i; p >= 0; {
			most_left_higher[i] = p
			if p != 0 && heights[p-1] >= v {
				p = most_left_higher[p-1]
			} else {
				break
			}
		}
	}
	for i := len(heights) - 1; i >= 0; i-- {
		v := heights[i]
		for p := i; p < len(heights); {
			most_right_higher[i] = p
			if p != len(heights)-1 && heights[p+1] >= v {
				p = most_right_higher[p+1]
			} else {
				break
			}
		}
	}
	//fmt.Println(most_left_higher)
	//fmt.Println(most_right_higher)
	result := 0
	for i, v := range heights {
		area := v * (most_right_higher[i] - most_left_higher[i] + 1)
		if area > result {
			result = area
		}
	}
	return result
}
