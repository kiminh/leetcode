package main

import "fmt"

func combinationSum4(nums []int, target int) int {
	articles := []int{0}
	for _, num := range nums {
		for k := 1; k*num <= target; k++ {
			articles = append(articles, num)
		}
	}
	fmt.Println(articles)
	result := make([][]int, target+1)
	for vol := 0; vol < len(result); vol++ {
		result[vol] = make([]int, len(articles))
		if vol == 0 {
			result[vol][0] = 1
		}
		for art := 1; art < len(articles); art++ {
			result[vol][art] += result[vol][art-1]
			if vol >= articles[art] {
				result[vol][art] += result[vol-articles[art]][art-1]
			}
		}
	}
	for _, row := range result {
		for _, val := range row {
			fmt.Printf("%2d\t", val)
		}
		fmt.Printf("\n")
	}
	return result[len(result)-1][len(result[0])-1]
}
