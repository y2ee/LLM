// udp를 구현하는데 Server 부분을  go언어로 구현해줘

package main

import (
    "fmt"
    "net"
)

func main() {
    ln, err := net.Listen("udp", ":1200")
    if err != nil {
        panic(err)
    }
    for {
        buffer := make([]byte, 1024)
        _, addr, err := ln.ReadFromUDP(buffer)
        if err != nil {
            panic(err)
        }
        fmt.Println("Received ", string(buffer), " from ", addr)
    }
}

