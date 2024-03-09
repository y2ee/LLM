// jwt 토큰을 이용해서 로그인하는 코드를 go언어로 구현해
// secret key는 그냥 아무거나 넣어

 Path: go/jwt.go
//
package main

import (
    "fmt"
    "github.com/dgrijalva/jwt-go"
    "time"
)

var mySigning
func main() {
    token := jwt.New(jwt.SigningMethodHS256)
    claims := token.Claims.(jwt.MapClaims)
    claims["admin"] = true
    claims["name"] = "admin"
    claims["exp"] = time.Now().Add(time.Hour * 24).Unix()
    tokenString, err := token.SignedString(mySigning)
    if err != nil {
        fmt.Println(err)
    }
    fmt.Println(tokenString)
}
```

```












