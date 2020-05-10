package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	fmt.Println(isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"))
	fmt.Println(isValidSerialization("1,#"))
}
