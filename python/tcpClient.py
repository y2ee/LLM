# tcp를 구현하는데 Client부분만  python언어로 구현해줘
# 서버 부분은 구현할 필요 없어

import socket
import struct
import random
import time

def main():
    # 서버 정보
    server_ip = ''
    server_port = 80

    # 소켓 생성
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # 서버에 연결
    client_socket.connect((server_ip, server_port))
    
    # SYN 패킷 생성
    seq_num = random.randint(0, 100)
    syn_packet = struct.pack('!I', seq_num) + struct.pack('!I', 0) + struct.pack('!I', 0x02) + struct.pack('!I', 0)

    # SYN 패킷 전송
    client_socket.send(syn_packet)

    # SYN/ACK 패킷 수신
    syn_ack_packet = client_socket.recv(1024)
    syn_ack_data = struct.unpack('!I', syn_ack_packet[0:4])[0]
    syn_ack_ack = struct.unpack('!I', syn_ack_packet[4:8])[0]
    syn_ack_flag = struct.unpack('!I', syn_ack_packet[8:12])[0]
    syn_ack_window = struct.unpack('!I', syn_ack_packet[12:16])[0]

    # ACK 패킷 생성
    ack_packet = struct.pack('!I', syn_ack_ack) + struct.pack('!I', syn_ack_data + 1) + struct.pack('!I', 0x10) + struct.pack('!I', 0)

    # ACK 패킷 전송
    client_socket.send(ack_packet)

    # 연결 종료
    client_socket.close()

if __name__ == '__main__':
    main()








