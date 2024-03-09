// udp를 구현하는데 Client 부분을  java언어로 구현해줘
// 서버부분은 구현할 필요 없어

import java.io.*;
import java.net.*;

public class udpClient {
    public static void main(String[] args) {
        try {
            DatagramSocket socket = new DatagramSocket();
            System.out.println("서버에 연결되었습니다.");

            byte[] sendData = "Hello Server".getBytes("UTF-8");
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, InetAddress.getByName("localhost"), 8080);
            socket.send(sendPacket);
            System.out.println("데이터를 보냈습니다.");

            byte[] receiveData = new byte[4096];
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            socket.receive(receivePacket);
            System.out.println("받은 데이터: " + new String(receivePacket.getData(), 0, receivePacket.getLength(), "UTF-8"));

            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}



























