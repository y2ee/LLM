// // 여러개의 알파벳을 입력받으면 같은 알파벳이 몇개인지 출력하는 go언어 코드를 만들어줘
// 참고로 사용자의 임력을 받는 부분도 만들어줘야해
// 예를 들어서 "hello"를 입력하면 h:1, e:1, l:2, o:1 이렇게 출력되어야해

package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	countAlphabet(input)
}

func countAlphabet(input string) {
	m := make(map[string]int)
	for _, c := range input {
		m[string(c)]++
	}
	for k, v := range m {
		fmt.Printf("%s:%d ", k, v)
	}
}

