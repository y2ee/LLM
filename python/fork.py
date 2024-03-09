# fork함수랑 vfork 함수를 사용하지 않고 자식 프로세스를 생성하는 코드를 python언어로 짜줘

import os

def main():
    print("부모 프로세스 시작")
    pid = os.fork()
    if pid == 0:
        print("자식 프로세스 시작")
    else:
        print("부모 프로세스 끝")

if __name__ == '__main__':
    main()
    










