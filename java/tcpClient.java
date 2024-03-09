// tcp를 구현하는데 Client부분만  java언어로 구현해줘
// 서버 부분은 구현할 필요 없어

import java.io.*;
import java.net.*;

public class tcpClient {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 8080);
            System.out.println("서버에 연결되었습니다.");

            InputStream in = socket.getInputStream();
            OutputStream out = socket.getOutputStream();

            out.write("Hello Server".getBytes("UTF-8"));
            out.flush();
            System.out.println("데이터를 보냈습니다.");

            byte[] buffer = new byte[4096];
            int readByteCount = in.read(buffer);
            if (readByteCount == -1) {
                throw new IOException();
            }
            System.out.println("받은 데이터: " + new String(buffer, 0, readByteCount, "UTF-8"));

            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}







