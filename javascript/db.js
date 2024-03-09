// 같은 패키지에 있는 mysql db에서 데이터를 송수신하는 코드를 javascript로 구현해줘

const db = require('mysql');
const connection = db.createConnection({
  host: 'localhost',
    user: 'root',
    password: 'password',
    database: 'test'
});

connection.connect();

connection.query('SELECT * FROM test', function (error, results, fields) {
    if (error) throw error;
    console.log('The solution is: ', results);
    }
);

connection.end();



