// udp를 구현하는데 Server 부분을  java언어로 구현해줘

import java.io.*;
import java.net.*;

public class udpServer {
    public static void main(String[] args) {
        try {
            DatagramSocket socket = new DatagramSocket(8080);
            System.out.println("클라이언트와 연결되었습니다.");

            byte[] receiveData = new byte[4096];
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            socket.receive(receivePacket);
            System.out.println("받은 데이터: " + new String(receivePacket.getData(), 0, receivePacket.getLength(), "UTF-8"));

            byte[] sendData = "Hello Client".getBytes("UTF-8");
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, receivePacket.getAddress(), receivePacket.getPort());
            socket.send(sendPacket);
            System.out.println("데이터를 보냈습니다.");

            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
    

