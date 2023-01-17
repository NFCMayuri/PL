<?php
if ($_POST["name"] == "" || ($_POST["sex"] != "male" && $_POST["sex"] != "female") || $_POST["class"] == "") {
    echo "请正确填写完整！";
    header("Refresh:2;url=add_ui.php");
} else {
    $db_host = "localhost";
    $db_username = "root";
    $db_password = "root";
    $db_name = "tang";
    $table_name = "user";
    $conn = mysqli_connect($db_host, $db_username, $db_password);
    mysqli_select_db($conn, $db_name);
    $sql = "INSERT into " . $table_name . " (name,sex,class) VALUES (\"" . $_POST["name"] . "\",\"" . $_POST["sex"] . "\",\"" . $_POST["class"] . "\");";
    $result = mysqli_query($conn, $sql);
    if (!$result) {
        echo "ERROR:" . mysqli_error($conn);
    } else {
        echo "添加成功";
    }
    header("Refresh:2;url=index.php");
}
?>