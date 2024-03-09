# 여러개의 알파벳을 입력받으면 같은 알파벳이 몇개인지 출력하는 python언어 코드를 끝까지 만들어줘
# 참고로 사용자의 입력을 받는 부분도 만들어줘야해
# 예를 들어서 "hello"를 입력하면 h:1, e:1, l:2, o:1 이렇게 출력되어야해

def countAlphabet():
	inputStr = input("알파벳을 입력하세요: ")
	alphabetDict = {}
	for i in inputStr:
		if i in alphabetDict:
			alphabetDict[i] += 1
		else:
			alphabetDict[i] = 1
	for key, value in alphabetDict.items():
		print(key, ":", value)

countAlphabet()






