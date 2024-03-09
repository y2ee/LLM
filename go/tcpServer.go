// tcp를 구현하는데 Server부분만  go언어로 구현해줘

Path: go/tcpServer.go

package main

import (
    "fmt"
    "net"
)

func main() {
    ln, err := net.Listen("tcp", ":8080")
    if err != nil {
        panic(err)
    }
    for {
        conn, err := ln.Accept()
        if err != nil {
            panic(err)
        }
        go handleConnection(conn)
    }
}

func handleConnection(conn net.Conn) {
    buffer := make([]byte, 1024)
    conn.Read(buffer)
    fmt.Println(string(buffer))
    conn.Write([]byte("Message received"))
    conn.Close()
}











