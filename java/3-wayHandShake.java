// java로 3-wayHandShake를 구현한 코드를 만들어주는데 이 파일 안에 다 구현해줘

import java.io.*;
import java.net.*;
import java.util.*;

public class 3-wayHandShake {
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
```

```java



