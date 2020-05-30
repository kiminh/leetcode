package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	fmt.Println(partition("aab"))
	fmt.Println(partition("abbaabbacccdc"))
}
