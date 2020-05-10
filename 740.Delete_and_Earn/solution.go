package main

func get_max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func deleteAndEarn(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	max := 0
	cnt := map[int]int{}
	for _, v := range nums {
		cnt[v]++
		if v > max {
			max = v
		}
	}
	data := make([]int, max+1)
	for k, v := range cnt {
		data[k] = k * v
	}
	//fmt.Println(data)
	result := make([]int, len(data))
	result[1] = data[1]
	for i := 2; i < len(result); i++ {
		result[i] = get_max(data[i]+result[i-2], result[i-1])

	}
	return result[len(result)-1]

}
