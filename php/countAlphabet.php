/* 여러개의 알파벳을 입력받으면 같은 알파벳이 몇개인지 출력하는 php언어 코드를 만들어줘
 참고로 사용자의 임력을 받는 부분도 만들어줘야해
 예를 들어서 "hello"를 입력하면 h:1, e:1, l:2, o:1 이렇게 출력되어야해 */

<!DOCTYPE html>
<html>
<head>
  <title>countAlphabet</title>
</head>
<body>
  <form action="countAlphabet.php" method="post">
	<input type="text" name="input" placeholder="input">
	<input type="submit" value="submit">
  </form>
  <?php
	if($_POST['input']){
	  $input = $_POST['input'];
	  $input = str_split($input);
	  $result = array();
	  for($i=0; $i<count($input); $i++){
		if(array_key_exists($input[$i], $result)){
		  $result[$input[$i]] += 1;
		}else{
		  $result[$input[$i]] = 1;
		}
	  }
	  foreach($result as $key => $value){
		echo $key.":".$value."<br>";
	  }
	}
  ?>
</body>
</html>
```






