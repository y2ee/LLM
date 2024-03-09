# udp를 구현하는데 Client 부분을  python언어로 구현해줘

# 서버부분은 구현할 필요 없어

import socket
import struct

def main():
    # 서버 정보
    server_ip = ''
    server_port = 80

    # 소켓 생성
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    # 데이터 전송
    client_socket.sendto(b'Hello, Server', (server_ip, server_port))

    # 데이터 수신
    data, addr = client_socket.recvfrom(1024)
    print(data.decode())

    # 연결 종료
    client_socket.close()

if __name__ == '__main__':
    main()




























