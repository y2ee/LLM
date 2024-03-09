// fork함수랑 vfork 함수를 사용하지 않고 자식 프로세스를 생성하는 코드를 go언어로 짜줘

Path: go/fork.go

package main

import (
    "fmt"
    "os"
)

func main() {
    fmt.Println("Parent process")
    pid := os.Getpid()
    fmt.Println("Parent process id: ", pid)

    _, err := os.ForkExec("/bin/ls", []string{"-l"}, nil)
    if err != nil {
        fmt.Println(err)
    }
    fmt.Println("Parent process")
}









