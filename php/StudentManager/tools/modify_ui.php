<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>修改</title>
</head>

<body>
    <form action="modify.php" method="post">
        id: &nbsp;&nbsp;&nbsp;&nbsp;<input type="text" name="id" value="<?php echo $_GET['id']; ?>"><br>
        姓名: <input type="text" name="name" value="<?php echo $_GET['name']; ?>"><br>
        性别: <input type="radio" name="sex" value="male" <?php echo ($_GET['sex'] == 'male') ? 'checked=true' : '' ?>>男
        <input type="radio" name="sex" value="female" <?php echo ($_GET['sex'] == 'female') ? 'checked=true' : '' ?>>女<br>
        班级: <input type="text" name="class" value="<?php echo $_GET['class']; ?>"><br>
        <input type="submit">
    </form>
</body>

</html>