# 같은 패키지에 있는 mysql db에서 데이터를 송수신하는 코드 python으로 작성해줘
# 1. 데이터베이스 연결
# 2. 데이터베이스 연결 해제
# 3. 데이터베이스에서 데이터를 가져오기

import pymysql

def connectDB():
    conn = pymysql.connect(host='localhost', 
    user ='root', 
    password='1234', 
    db='test', 
    charset='utf8')
    return conn
    
def disconnectDB(conn):
    conn.close()

def getData():
    conn = connectDB()
    cursor = conn.cursor()
    sql = "SELECT * FROM test"
    cursor.execute(sql)
    result = cursor.fetchall()
    disconnectDB(conn)
    return result

