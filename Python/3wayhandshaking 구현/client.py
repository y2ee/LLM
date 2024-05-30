import socket


def client_three_way_handshake(server_ip, server_port):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    client_socket.connect((server_ip, server_port))
    client_socket.send(b'SYN')

    syn_ack = client_socket.recv(1024)
    print("Received SYN-ACK from server:", syn_ack.decode())

    client_socket.send(b'ACK')

    print("Connection established.")
    client_socket.close()


if __name__ == "__main__":
    server_ip = '127.0.0.1'
    server_port = 12345
    client_three_way_handshake(server_ip, server_port)
