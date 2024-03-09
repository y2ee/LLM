// fork함수랑 vfork 함수를 사용하지 않고 자식 프로세스를 생성하는 코드를 java언어로 짜줘

import java.io.*;

public class fork {
    public static void main(String[] args) {
        try {
            ProcessBuilder pb = new ProcessBuilder("java", "fork");
            Process p = pb.start();
            p.waitFor();
            System.out.println("자식 프로세스가 종료되었습니다.");
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}










