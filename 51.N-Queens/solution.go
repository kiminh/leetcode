package main

type Coor_t struct {
	Row int
	Col int
}
type Bitmap_t map[int]bool
type Record_t map[Coor_t]bool

func check(n, pos, row int, record *Record_t) bool {
	for step := 1; row-step >= 0; step++ {
		if pos-step >= 0 {
			if _, ok := (*record)[Coor_t{row - step, pos - step}]; ok {
				return false
			}
		}
		if pos+step < n {
			if _, ok := (*record)[Coor_t{row - step, pos + step}]; ok {
				return false
			}
		}

	}
	return true
}

func nq(n, row int, record *Record_t, bm *Bitmap_t, result *[][]string) {
	if row == n {
		temp := make([][]byte, n)
		for i := range temp {
			temp[i] = make([]byte, n)
			for t := range temp[i] {
				temp[i][t] = '.'
			}
		}
		for k, _ := range *record {
			temp[k.Row][k.Col] = 'Q'
		}
		temp_str := make([]string, 0, n)
		for _, row_data := range temp {
			temp_str = append(temp_str, string(row_data))
		}
		*result = append(*result, temp_str)
	}
	for pos := 0; pos < n; pos++ {
		if _, ok := (*bm)[pos]; !ok && check(n, pos, row, record) {
			(*record)[Coor_t{row, pos}] = true
			(*bm)[pos] = true
			nq(n, row+1, record, bm, result)
			delete(*record, Coor_t{row, pos})
			delete(*bm, pos)
		}
	}
}

func solveNQueens(n int) [][]string {
	result := [][]string{}
	record := make(Record_t)
	empty_row := make([]byte, n)
	for i := range empty_row {
		empty_row[i] = '.'
	}
	snap := make([][]byte, n)
	for i := range snap {
		snap[i] = make([]byte, n)
		for t := range snap[i] {
			snap[i][t] = '.'
		}
	}
	bitmap := Bitmap_t{}
	nq(n, 0, &record, &bitmap, &result)
	return result
}
