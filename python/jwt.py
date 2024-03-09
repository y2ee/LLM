# jwt 토큰을 이용해서!!!! 로그인하는 과정을 python로 구현해줘 

import jwt
import datetime
import time
import json

def createToken():
    payload = {
        'id': 'user_id',
        'exp': datetime.datetime.utcnow() + datetime.timedelta(seconds=10)
    }
    secret
    token = jwt.encode(payload, secret, algorithm='HS256')
    return token

def verifyToken(token):
    try:
        payload = jwt.decode(token, secret, algorithms=['HS256'])
        return True
    except jwt.ExpiredSignatureError:
        return False
    except jwt.InvalidTokenError:
        return False

def main():
    token = createToken()
    print(token)
    time.sleep(5)
    print(verifyToken(token))
    time.sleep(5)
    print(verifyToken(token))

if __name__ == '__main__':
    main()
    


























