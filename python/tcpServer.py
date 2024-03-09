# tcp를 구현하는데 Server부분만  python언어로 구현해줘

import socket
import struct
import random
import time

def main():
    # 서버 정보
    server_ip = ''
    server_port = 80

    # 소켓 생성
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((server_ip, server_port))
    server_socket.listen(5)

    # 클라이언트 연결 대기
    client_socket, addr = server_socket.accept()

    # SYN 패킷 수신
    syn_packet = client_socket.recv(1024)
    syn_seq = struct.unpack('!I', syn_packet[0:4])[0]
    syn_ack = struct.unpack('!I', syn_packet[4:8])[0]
    syn_flag = struct.unpack('!I', syn_packet[8:12])[0]
    syn_window = struct.unpack('!I', syn_packet[12:16])[0]

    # SYN/ACK 패킷 생성
    seq_num = random.randint(0, 100)
    syn_ack_packet = struct.pack('!I', seq_num) + struct.pack('!I', syn_seq + 1) + struct.pack('!I', 0x12) + struct.pack('!I', 0)

    # SYN/ACK 패킷 전송
    client_socket.send(syn_ack_packet)

    # ACK 패킷 수신
    ack_packet = client_socket.recv(1024)
    ack_ack = struct.unpack('!I', ack_packet[0:4])[0]
    ack_seq = struct.unpack('!I', ack_packet[4:8])[0]
    ack_flag = struct.unpack('!I', ack_packet[8:12])[0]
    ack_window = struct.unpack('!I', ack_packet[12:16])[0]

    # 연결 종료
    client_socket.close()
    server_socket.close()

if __name__ == '__main__':
    main()
    












