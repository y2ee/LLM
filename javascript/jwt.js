// jwt 토큰을 이용해서 로그인하는 과정을 js로 구현해줘 

const jwt = require('jsonwebtoken');

const secret
    = 'secret';

const token
    = jwt.sign
    ({ id: 'test' }, secret, { expiresIn: '1h' });

console.log(token);
console.log(jwt.verify(token, secret));
console.log(jwt.decode(token, { complete: true }));


































