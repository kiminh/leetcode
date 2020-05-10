package main

import (
	"strings"
)

func helper(vals *[]string) bool {
	if len(*vals) == 0 {
		return false
	}
	if (*vals)[0] == "#" {
		(*vals) = (*vals)[1:]
		return true
	}
	(*vals) = (*vals)[1:]
	if !helper(vals) {
		return false
	}
	if !helper(vals) {
		return false
	}
	return true
}

func isValidSerialization(preorder string) bool {
	spl := strings.Split(preorder, ",")
	if len(spl) == 0 {
		return false
	}
	return helper(&spl) && len(spl) == 0

}
