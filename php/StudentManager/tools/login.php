<?php
$username = $_POST['username'];
$password = $_POST['password'];
$db_host = "localhost";
$db_username = "root";
$db_password = "root";
$db_name = "tang";
$table_name = "account";
$conn = mysqli_connect($db_host, $db_username, $db_password);
mysqli_select_db($conn, $db_name);
$sql = "SELECT * from `" . $table_name . "`;";
$result = mysqli_query($conn, $sql);
if (!$result) {
    die("ERROR:" . mysqli_error($conn));
}
if ($username == "" || $password == "") {
    echo ("账号或密码为空");
    header("Refresh:2;url=login_ui.php");
} else {
    $flag = 0;
    while ($item = mysqli_fetch_assoc($result)) {
        if ($item["username"] != $username) {
            continue;
        }
        if ($item["password"] != $password) {
            $flag = 1;
            echo "密码错误<br>";
            header("Refresh:2;url=login_ui.php");
            break;
        }
        $flag = 2;
        echo "登陆成功";
        setcookie('username', $username, time() + 3600);
        setcookie('password', $password, time() + 3600);
        //暂时先这样保存登录状态好了
        header("Refresh:2;url=../index.php");
    }
    if (!$flag) {
        echo "账号不存在<br>";
        header("Refresh:2;url=login_ui.php");
    }
}
?>