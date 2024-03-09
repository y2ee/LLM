// // 여러개의 알파벳을 입력받으면 같은 알파벳이 몇개인지 출력하는 javascript언어 코드를 만들어줘
// 참고로 사용자의 임력을 받는 부분도 만들어줘야해
// 예를 들어서 "hello"를 입력하면 h:1, e:1, l:2, o:1 이렇게 출력되어야해

const countAlphabet = (input) => {
  const count = new Array(26).fill(0);
  for (let i = 0; i < input.length; i++) {
	const c = input[i];
	if (c >= 'a' && c <= 'z') {
	  count[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
	} else if (c >= 'A' && c <= 'Z') {
	  count[c.charCodeAt(0) - 'A'.charCodeAt(0)]++;
	}
  }

  const result = [];
  for (let i = 0; i < 26; i++) {
	if (count[i] > 0) {
	  result.push(String.fromCharCode('a'.charCodeAt(0) + i) + ': ' + count[i]);
	}
  }
  return result;
};

console.log(countAlphabet('hello'));
// ['h: 1', 'e: 1', 'l: 2', 'o: 1']
console.log(countAlphabet('hello world'));
// ['h: 1', 'e: 1', 'l: 3', 'o: 2', 'r: 1', 'd: 1', 'w: 1']
console.log(countAlphabet('Hello World'));
// ['H: 1', 'e: 1', 'l: 3', 'o: 2', 'r: 1', 'd: 1', 'W: 1']



