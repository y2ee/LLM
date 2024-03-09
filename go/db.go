// mysql db에 연결을 해서  users 디비에서 email, name값을 불러오는 go언어 코드 짜줘

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

func getUsers() {
	rows, err := db.Query("SELECT email, name FROM users")
	if err != nil {
		panic(err.Error())
	}
	defer rows.Close()

	for rows.Next() {
		var email string
		var name string
		err = rows.Scan(&email, &name)
		if err != nil {
			panic(err.Error())
		}
		fmt.Println(email, name)
	}
}


