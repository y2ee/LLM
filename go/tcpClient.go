// tcp를 구현하는데 Client부분만  go언어로 구현해줘
// 서버 부분은 구현할 필요 없어

package main

import (
    "fmt"
    "net"
    "os"
    "time"
)

func main() {
    
        service := "localhost:1200"
    
        tcpAddr, err := net.ResolveTCPAddr("tcp4", service)
        checkError(err)
    
        conn, err := net.DialTCP("tcp", nil, tcpAddr)
        checkError(err)
    
        _, err = conn.Write([]byte("HEAD / HTTP/1.0\r\n\r\n"))
        checkError(err)
    
        result, err := readFully(conn)
        checkError(err)
    
        fmt.Println(string(result))
    
        os.Exit(0)
    }

func checkError(err error) {
    if err != nil {
        fmt.Fprintf(os.Stderr, "Fatal error: %s", err.Error())
        os.Exit(1)
    }
}

func readFully(conn net.Conn) ([]byte, error) {
    defer conn.Close()

    result := bytes.NewBuffer(nil)
    var buf [512]byte
    for {
        n, err := conn.Read(buf[0:])
        result.Write(buf[0:n])
        if err != nil {
            if err == io.EOF {
                break
            }
            return nil, err
        }
    }
    return result.Bytes(), nil
}






