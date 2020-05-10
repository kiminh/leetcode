package main

func dfs(s string, row, col int, visited *[][]bool, board *[][]byte) bool {
	if len(s) == 0 {
		return true
	}
	if row < 0 || row >= len((*visited)) {
		return false
	}
	if col < 0 || col >= len((*visited)[0]) {
		return false
	}
	if (*visited)[row][col] == true {
		return false
	}
	if (*board)[row][col] != s[0] {
		return false
	}
	(*visited)[row][col] = true
	if dfs(s[1:], row-1, col, visited, board) {
		return true
	}
	if dfs(s[1:], row+1, col, visited, board) {
		return true
	}

	if dfs(s[1:], row, col-1, visited, board) {
		return true
	}
	if dfs(s[1:], row, col+1, visited, board) {
		return true
	}
	(*visited)[row][col] = false
	return false
}

func exist(board [][]byte, word string) bool {
	for row := 0; row < len(board); row++ {
		for col := 0; col < len(board[row]); col++ {
			if board[row][col] == word[0] {
				visited := make([][]bool, len(board))
				for i := range visited {
					visited[i] = make([]bool, len(board[0]))
				}
				if dfs(word, row, col, &visited, &board) {
					return true
				}
			}
		}
	}
	return false
}
