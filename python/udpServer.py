# udp를 구현하는데 Server 부분을  python언어로 구현해줘

import socket
import struct

def main():
    # 서버 정보
    server_ip = ''
    server_port = 80

    # 소켓 생성
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind((server_ip, server_port))

    # 데이터 수신
    data, addr = server_socket.recvfrom(1024)
    print(data.decode())

    # 데이터 전송
    server_socket.sendto(b'Hello, Client', addr)

    # 연결 종료
    server_socket.close()

if __name__ == '__main__':
    main()
    
    

