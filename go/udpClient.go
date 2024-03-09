// udp를 구현하는데 Client 부분을  go언어로 구현해줘
// 서버부분은 구현할 필요 없어

package main

import (
    "fmt"
    "net"
    "os"
)

func main() {
    service := "localhost:1200"
    udpAddr, err := net.ResolveUDPAddr("udp4", service)
    checkError(err)
    conn, err := net.DialUDP("udp", nil, udpAddr)
    checkError(err)
    _, err = conn.Write([]byte("anything"))
    checkError(err)
    os.Exit(0)
}

func checkError(err error) {
    if err != nil {
        fmt.Fprintf(os.Stderr, "Fatal error: %s", err.Error())
        os.Exit(1)
    }
}

























