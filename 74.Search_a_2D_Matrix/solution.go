package main

func find_row(matrix [][]int, target int) int {
	l, r := 0, len(matrix)-1
	for l <= r {
		mid := (l + r) / 2
		if len(matrix[mid]) == 0 {
			return -1
		}
		if matrix[mid][0] == target {
			return mid
		} else if matrix[mid][0] < target {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	return r
}

func searchMatrix(matrix [][]int, target int) bool {
	row := find_row(matrix, target)
	if row == -1 {
		return false
	}
	for l, r := 0, len(matrix[row])-1; l <= r; {
		mid := (l + r) / 2
		if matrix[row][mid] == target {
			return true
		} else if matrix[row][mid] < target {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	return false
}
