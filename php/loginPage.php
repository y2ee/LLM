/* 기부 홈페이지의 로그인 페이지를 php를 사용해서 구현해줘 */

<!DOCTYPE html>
<html>
<head>
  <title>login</title>
</head>
<body>
  <form action="login.php" method="post">
    <input type="text" name="id" placeholder="id">
    <input type="password" name="password" placeholder="password">
    <input type="submit" value="submit">
  </form>
  <?php
    if($_POST['id'] && $_POST['password']){
      $id = $_POST['id'];
      $password = $_POST['password'];
      if($id == "admin" && $password == "admin"){
        echo "login success";
      }else{
        echo "login fail";
      }
    }
  ?>
</body>
</html>
```


