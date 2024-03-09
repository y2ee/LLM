// 사용자가 email, password를 입력하면 그 값을 연결된 mysql 디비에 있는 값이랑 비교를 해서 맞으면 로그인 성공을 띄우는 go언어 프로그램을 만들어주라
// 이때 mysql 디비에는 email, password가 저장되어 있다.

Path: go/login.go

package main

import (
    "database/sql"
    "fmt"
    _ "github.com/go-sql-driver/mysql"
)

func main() {
    db, err := sql.Open("mysql", "root:root@tcp")
    if err != nil {
        panic(err.Error())
    }
    defer db.Close()

    var email, password string
    fmt.Scanln(&email, &password)
    login(email, password)
}

func login(email, password string) {
    rows, err := db.Query("SELECT email, password FROM users WHERE email = ? AND password = ?", email, password)
    if err != nil {
        panic(err.Error())
    }
    defer rows.Close()

    if rows.Next() {
        fmt.Println("Login Success")
    } else {
        fmt.Println("Login Failed")
    }
}


