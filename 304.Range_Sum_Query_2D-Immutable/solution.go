package main

type NumMatrix struct {
	Matrix [][]int
	CntRow int
	CntCol int
}

func Constructor(matrix [][]int) NumMatrix {
	var result NumMatrix
	result.Matrix = make([][]int, len(matrix))
	for i, _ := range result.Matrix {
		result.Matrix[i] = make([]int, len(matrix[i]))
		copy(result.Matrix[i], matrix[i])
	}
	for row := 0; row < len(result.Matrix); row++ {
		for col := 0; col < len(result.Matrix[row]); col++ {
			if row == 0 {
				if col > 0 {
					result.Matrix[row][col] += result.Matrix[row][col-1]
				}
			} else if col == 0 {
				if row > 0 {
					result.Matrix[row][col] += result.Matrix[row-1][col]
				}
			} else {
				result.Matrix[row][col] += result.Matrix[row-1][col] + result.Matrix[row][col-1] - result.Matrix[row-1][col-1]
			}
		}
	}
	return result

}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	result := this.Matrix[row2][col2]
	if col1 > 0 {
		result -= this.Matrix[row2][col1-1]
	}
	if row1 > 0 {
		result -= this.Matrix[row1-1][col2]
	}
	if row1 > 0 && col1 > 0 {
		result += this.Matrix[row1-1][col1-1]
	}
	return result
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
