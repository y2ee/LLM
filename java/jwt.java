// jwt 토큰을 이용해서!!!! 로그인하는 과정을 java로 구현해줘 

import java.io.*;
import java.net.*;
import java.util.*;


public class jwt {
    public static void main(String[] args) {
        try {
            ServerSocket server = new ServerSocket(8080);
            Socket client = server.accept();
            System.out.println("클라이언트와 연결되었습니다.");

            InputStream in = client.getInputStream();
            OutputStream out = client.getOutputStream();

            byte[] buffer = new byte[4096];
            int readByteCount = in.read(buffer);
            if (readByteCount == -1) {
                throw new IOException();
            }
            System.out.println("받은 데이터: " + new String(buffer, 0, readByteCount, "UTF-8"));

            out.write("Hello Client".getBytes("UTF-8"));
            out.flush();
            System.out.println("데이터를 보냈습니다.");

            client.close();
            server.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
// ```
//
//
//
//



























