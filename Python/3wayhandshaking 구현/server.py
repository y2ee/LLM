import socket


def server_three_way_handshake(server_port):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('127.0.0.1', server_port))
    server_socket.listen(1)

    print("Server is listening on port", server_port)

    while True:
        client_socket, client_address = server_socket.accept()

        syn_packet = client_socket.recv(1024)
        print("Received SYN from client:", syn_packet.decode())
        client_socket.send(b'SYN-ACK')

        ack_packet = client_socket.recv(1024)
        print("Received ACK from client:", ack_packet.decode())

        print("Connection established with", client_address)
        client_socket.close()


if __name__ == "__main__":
    server_port = 12345
    server_three_way_handshake(server_port)
