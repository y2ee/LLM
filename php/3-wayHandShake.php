/* 3-wayHandShake를 php 언어로 코드를 짜줘 */

 <!DOCTYPE html>
<html>
<head>
  <title>3-wayHandShake</title>
</head>
<body>
  <form action="3-wayHandShake.php" method="post">
    <input type="text" name="input" placeholder="input">
    <input type="submit" value="submit">
  </form>
  <?php
    if($_POST['input']){
      $input = $_POST['input'];
      $input = explode(" ", $input);
      $input = array_map('intval', $input);
      $result = 0;
      for($i=0; $i<count($input); $i++){
        $result += $input[$i];
      }
      echo $result;
    }
  ?>
</body>
</html>
```

