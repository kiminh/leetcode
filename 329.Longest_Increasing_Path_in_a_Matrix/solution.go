package main

func longestIncreasingPath(matrix [][]int) int {
	if len(matrix) == 0 {
		return 0
	}
	heigth := len(matrix)
	width := len(matrix[0])
	result := make([][]int, heigth)
	for i := 0; i < heigth; i++ {
		result[i] = make([]int, width)
	}
	for true {
		change := false
		for row := 0; row < heigth; row++ {
			for col := 0; col < width; col++ {
				current := matrix[row][col]
				if col > 0 && current > matrix[row][col-1] && result[row][col-1]+1 > result[row][col] {
					//left
					result[row][col] = result[row][col-1] + 1
					change = true
				}
				if col < width-1 && current > matrix[row][col+1] && result[row][col+1]+1 > result[row][col] {
					//right
					result[row][col] = result[row][col+1] + 1
					change = true
				}
				if row > 0 && current > matrix[row-1][col] && result[row-1][col]+1 > result[row][col] {
					//up
					result[row][col] = result[row-1][col] + 1
					change = true
				}
				if row < heigth-1 && current > matrix[row+1][col] && result[row+1][col]+1 > result[row][col] {
					//up
					result[row][col] = result[row+1][col] + 1
					change = true
				}
			}
		}
		if !change {
			break
		}
	}
	max_len := 0
	for _, row := range result {
		for _, val := range row {
			if val > max_len {
				max_len = val
			}
		}
	}
	return max_len + 1
}
