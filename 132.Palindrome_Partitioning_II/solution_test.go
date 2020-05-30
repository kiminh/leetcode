package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	fmt.Println(minCut("abbaabbacccdc"))
	fmt.Println(minCut("cbbbcc"))
}
