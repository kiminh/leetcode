package main

type NumArray struct {
	Accu []int
}

func Constructor(nums []int) NumArray {
	res := NumArray{make([]int, len(nums))}
	for i, v := range nums {
		if i == 0 {
			res.Accu[i] = v
			continue
		}
		res.Accu[i] = res.Accu[i-1] + v
	}
	return res
}

func (this *NumArray) SumRange(i int, j int) int {
	if i-1 < 0 {
		return this.Accu[j]
	}
	return this.Accu[j] - this.Accu[i-1]
}
