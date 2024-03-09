// 같은 패키지에 있는 mysql db에서 데이터를 송수신하는 코드 작성해줘
// 1. 데이터베이스 연결
// 2. 데이터베이스 연결 해제
// 3. 데이터베이스에서 데이터를 가져오기

import java.sql.*;

public class db {
    public static void main(String[] args) {
        try {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "1234");
            System.out.println("데이터베이스에 연결되었습니다.");

            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM test");

            while (rs.next()) {
                System.out.println(rs.getString("name"));
            }

            rs.close();
            stmt.close();
            conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
