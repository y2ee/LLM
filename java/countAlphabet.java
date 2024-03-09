// // 여러개의 알파벳을 입력받으면 같은 알파벳이 몇개인지 출력하는 java언어 코드를 만들어줘
// 참고로 사용자의 임력을 받는 부분도 만들어줘야해
// 예를 들어서 "hello"를 입력하면 h:1, e:1, l:2, o:1 이렇게 출력되어야해

import java.util.Scanner;

public class countAlphabet {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		sc.close();

		int[] count = new int[26];
		for (int i = 0; i < input.length(); i++) {
			char c = input.charAt(i);
			if (c >= 'a' && c <= 'z') {
				count[c - 'a']++;
			} else if (c >= 'A' && c <= 'Z') {
				count[c - 'A']++;
			}
		}

		for (int i = 0; i < 26; i++) {
			if (count[i] > 0) {
				System.out.println((char) ('a' + i) + ": " + count[i]);
			}
		}
	}
}
```


